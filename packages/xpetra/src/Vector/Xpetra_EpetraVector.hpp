// @HEADER
//
// ***********************************************************************
//
//             Xpetra: A linear algebra interface package
//                  Copyright 2012 Sandia Corporation
//
// Under the terms of Contract DE-AC04-94AL85000 with Sandia Corporation,
// the U.S. Government retains certain rights in this software.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// 1. Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
//
// 3. Neither the name of the Corporation nor the names of the
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY SANDIA CORPORATION "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL SANDIA CORPORATION OR THE
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Questions? Contact
//                    Jonathan Hu       (jhu@sandia.gov)
//                    Andrey Prokopenko (aprokop@sandia.gov)
//                    Ray Tuminaro      (rstumin@sandia.gov)
//
// ***********************************************************************
//
// @HEADER
#ifndef XPETRA_EPETRAVECTOR_HPP
#define XPETRA_EPETRAVECTOR_HPP

/* this file is automatically generated - do not edit (see script/epetra.py) */

#include "Xpetra_EpetraConfigDefs.hpp"

#include "Xpetra_Vector.hpp"
#include "Xpetra_EpetraMultiVector.hpp"
#include "Xpetra_EpetraMap.hpp"  //TMP
#include "Xpetra_Utils.hpp"
#include "Xpetra_EpetraImport.hpp"
#include "Xpetra_EpetraExport.hpp"
#include "Xpetra_Exceptions.hpp"

#include <Epetra_Vector.h>

namespace Xpetra {

// TODO: move that elsewhere
template <class GlobalOrdinal, class Node>
Epetra_Vector &toEpetra(Vector<double, int, GlobalOrdinal, Node> &);

template <class GlobalOrdinal, class Node>
const Epetra_Vector &toEpetra(const Vector<double, int, GlobalOrdinal, Node> &);
//

template <class EpetraGlobalOrdinal, class Node>
class EpetraVectorT
  : public virtual Vector<double, int, EpetraGlobalOrdinal, Node>,
    public EpetraMultiVectorT<EpetraGlobalOrdinal, Node> {
  typedef double Scalar;
  typedef int LocalOrdinal;
  typedef EpetraGlobalOrdinal GlobalOrdinal;

 public:
  //! Compute 1-norm of each vector in multi-vector.
  void norm1(const Teuchos::ArrayView<Teuchos::ScalarTraits<Scalar>::magnitudeType> &norms) const {}

  //!
  void norm2(const Teuchos::ArrayView<Teuchos::ScalarTraits<Scalar>::magnitudeType> &norms) const {}

  //! Compute Inf-norm of each vector in multi-vector.
  void normInf(const Teuchos::ArrayView<Teuchos::ScalarTraits<Scalar>::magnitudeType> &norms) const {}

  //! Compute mean (average) value of each vector in multi-vector. The outcome of this routine is undefined for non-floating point scalar types (e.g., int).
  void meanValue(const Teuchos::ArrayView<Scalar> &means) const {}

  //! Replace value, using global (row) index.
  void replaceGlobalValue(GlobalOrdinal globalRow, size_t vectorIndex, const Scalar &value) {}

  //! Add value to existing value, using global (row) index.
  void sumIntoGlobalValue(GlobalOrdinal globalRow, size_t vectorIndex, const Scalar &value) {}

  //! Replace value, using local (row) index.
  void replaceLocalValue(LocalOrdinal myRow, size_t vectorIndex, const Scalar &value) {}

  //! Add value to existing value, using local (row) index.
  void sumIntoLocalValue(LocalOrdinal myRow, size_t vectorIndex, const Scalar &value) {}

  //! Compute the dot product of each corresponding pair of vectors (columns) in A and B.
  void dot(const MultiVector<Scalar, LocalOrdinal, GlobalOrdinal, Node> &A, const Teuchos::ArrayView<Scalar> &dots) const {}

  //! @name Constructor/Destructor Methods
  //@{

  //! Sets all vector entries to zero.
  explicit EpetraVectorT(const RCP<const Map<LocalOrdinal, GlobalOrdinal, Node> > &map, bool zeroOut = true)
    : EpetraMultiVectorT<GlobalOrdinal, Node>(map, 1, zeroOut){};

  // Commenting out since no definition provided in cpp.
  //! Vector copy constructor.
  // EpetraVectorT(const Vector< Scalar, LocalOrdinal, GlobalOrdinal, Node > &source);

  //! Destructor.
  virtual ~EpetraVectorT() {}

  //@}

  //! @name Post-construction modification routines
  //@{

  //! Replace current value at the specified location with specified value.
  void replaceGlobalValue(GlobalOrdinal globalRow, const Scalar &value){};

  //! Adds specified value to existing value at the specified location.
  void sumIntoGlobalValue(GlobalOrdinal globalRow, const Scalar &value){};

  //! Replace current value at the specified location with specified values.
  void replaceLocalValue(LocalOrdinal myRow, const Scalar &value){};

  //! Adds specified value to existing value at the specified location.
  void sumIntoLocalValue(LocalOrdinal myRow, const Scalar &value){};

  //@}

  //! @name Mathematical methods
  //@{

  //! Computes dot product of this Vector against input Vector x.
  Scalar dot(const Vector<Scalar, LocalOrdinal, GlobalOrdinal, Node> &a) const { return Teuchos::ScalarTraits<Scalar>::zero(); };

  //! Return 1-norm of this Vector.
  Teuchos::ScalarTraits<Scalar>::magnitudeType norm1() const { return Teuchos::ScalarTraits<Scalar>::magnitude(Teuchos::ScalarTraits<Scalar>::zero()); };

  //! Compute 2-norm of this Vector.
  Teuchos::ScalarTraits<Scalar>::magnitudeType norm2() const { return Teuchos::ScalarTraits<Scalar>::magnitude(Teuchos::ScalarTraits<Scalar>::zero()); };

  //! Compute Inf-norm of this Vector.
  Teuchos::ScalarTraits<Scalar>::magnitudeType normInf() const { return Teuchos::ScalarTraits<Scalar>::magnitude(Teuchos::ScalarTraits<Scalar>::zero()); };

  //! Compute Weighted 2-norm (RMS Norm) of this Vector.
  // Teuchos::ScalarTraits< Scalar >::magnitudeType normWeighted(const Vector< Scalar, LocalOrdinal, GlobalOrdinal, Node > &weights) const;

  //! Compute mean (average) value of this Vector.
  Scalar meanValue() const { return Teuchos::ScalarTraits<Scalar>::zero(); };

  //@}

  //! @name Overridden from Teuchos::Describable
  //@{

  //! Return a simple one-line description of this object.
  std::string description() const { return std::string(""); }

  //! Print the object with some verbosity level to an FancyOStream object.
  void describe(Teuchos::FancyOStream &out, const Teuchos::EVerbosityLevel verbLevel = Teuchos::Describable::verbLevel_default) const {};

  //@}

  //! @name Xpetra specific
  //@{

  //! EpetraMultiVectorT constructor to wrap a Epetra_Vector object
  EpetraVectorT(const Teuchos::RCP<Epetra_Vector> &vec)
    : EpetraMultiVectorT<GlobalOrdinal, Node>(vec) {  // TODO: removed const of Epetra::Vector
    TEUCHOS_TEST_FOR_EXCEPTION(true, Xpetra::Exceptions::RuntimeError,
                               "Xpetra::EpetraVector only available for GO=int or GO=long long with EpetraNode (Serial or OpenMP depending on configuration)");
  }

  //! Get the underlying Epetra vector
  Epetra_Vector *getEpetra_Vector() const { return NULL; /*return (*this->EpetraMultiVectorT<GlobalOrdinal, Node>::getEpetra_MultiVector())(0);*/ }
  // RCP<Epetra_Vector> getEpetra_Vector() const { return this->EpetraMultiVectorT<GlobalOrdinal>::getEpetra_MultiVector()->getVectorNonConst(0); }

  //! This constructor creates a Vector which is a view of column j of the MultiVector 'mv'.
  //! It implements the logic of MultiVector::getVector/getVectorNonConst() for Epetra MultiVector.
  //! The newly created Xpetra::EpetraVectorT will remain valid after the disappearance of the references to 'mv' in user code.
  EpetraVectorT(const RCP<Epetra_MultiVector> &mv, size_t j)
    : EpetraMultiVectorT<GlobalOrdinal, Node>(mv){};

  //@}

 private:
  // This private member is only used by the constructor EpetraVectorT(const RCP<EpetraMultiVectorT<GlobalOrdinal> > &mv, size_t j). The actual private member holding the Epetra vector (vec_) is in the base class (Xpetra:EpetraMultiVectorT)
  // TODO remove this...
  const RCP<const Epetra_MultiVector> internalRefToBaseMV_;

};  // EpetraVectorT class

// specialization on GO=int and Node=Serial
#ifndef XPETRA_EPETRA_NO_32BIT_GLOBAL_INDICES
template <>
class EpetraVectorT<int, EpetraNode>
  : public virtual Vector<double, int, int, EpetraNode>, public EpetraMultiVectorT<int, EpetraNode> {
  typedef double Scalar;
  typedef int LocalOrdinal;
  typedef int GlobalOrdinal;
  typedef EpetraNode Node;

 public:
  using EpetraMultiVectorT<GlobalOrdinal, Node>::dot;                 // overloading, not hiding
  using EpetraMultiVectorT<GlobalOrdinal, Node>::norm1;               // overloading, not hiding
  using EpetraMultiVectorT<GlobalOrdinal, Node>::norm2;               // overloading, not hiding
  using EpetraMultiVectorT<GlobalOrdinal, Node>::normInf;             // overloading, not hiding
  using EpetraMultiVectorT<GlobalOrdinal, Node>::meanValue;           // overloading, not hiding
  using EpetraMultiVectorT<GlobalOrdinal, Node>::replaceGlobalValue;  // overloading, not hiding
  using EpetraMultiVectorT<GlobalOrdinal, Node>::sumIntoGlobalValue;  // overloading, not hiding
  using EpetraMultiVectorT<GlobalOrdinal, Node>::replaceLocalValue;   // overloading, not hiding
  using EpetraMultiVectorT<GlobalOrdinal, Node>::sumIntoLocalValue;   // overloading, not hiding

  //! @name Constructor/Destructor Methods
  //@{

  //! Sets all vector entries to zero.
  explicit EpetraVectorT(const Teuchos::RCP<const Map<int, GlobalOrdinal, Node> > &map, bool zeroOut = true)
    : EpetraMultiVectorT<GlobalOrdinal, Node>(map, 1, zeroOut) {}

  // Commenting out since no definition provided in cpp.
  //! Vector copy constructor.
  // EpetraVectorT(const Vector< Scalar, LocalOrdinal, GlobalOrdinal, Node > &source);

  //! Destructor.
  virtual ~EpetraVectorT() {}

  //@}

  //! @name Post-construction modification routines
  //@{

  //! Replace current value at the specified location with specified value.
  void replaceGlobalValue(GlobalOrdinal globalRow, const Scalar &value) {
    XPETRA_MONITOR("EpetraVectorT::replaceGlobalValue");
    this->EpetraMultiVectorT<GlobalOrdinal, Node>::getEpetra_MultiVector()->ReplaceGlobalValue(globalRow, 0, value);
  }

  //! Adds specified value to existing value at the specified location.
  void sumIntoGlobalValue(GlobalOrdinal globalRow, const Scalar &value) {
    XPETRA_MONITOR("EpetraVectorT::sumIntoGlobalValue");
    this->EpetraMultiVectorT<GlobalOrdinal, Node>::getEpetra_MultiVector()->SumIntoGlobalValue(globalRow, 0, value);
  }

  //! Replace current value at the specified location with specified values.
  void replaceLocalValue(LocalOrdinal myRow, const Scalar &value) {
    XPETRA_MONITOR("EpetraVectorT::replaceLocalValue");
    this->EpetraMultiVectorT<GlobalOrdinal, Node>::getEpetra_MultiVector()->ReplaceMyValue(myRow, 0, value);
  }

  //! Adds specified value to existing value at the specified location.
  void sumIntoLocalValue(LocalOrdinal myRow, const Scalar &value) {
    XPETRA_MONITOR("EpetraVectorT::sumIntoLocalValue");
    this->EpetraMultiVectorT<GlobalOrdinal, Node>::getEpetra_MultiVector()->SumIntoMyValue(myRow, 0, value);
  }

  //@}

  //! @name Mathematical methods
  //@{

  //! Computes dot product of this Vector against input Vector x.
  Scalar dot(const Vector<Scalar, LocalOrdinal, GlobalOrdinal, Node> &a) const {
    XPETRA_MONITOR("EpetraVectorT::dot");

    XPETRA_DYNAMIC_CAST(const EpetraVectorT, a, tA, "This Xpetra::EpetraVectorT method only accept Xpetra::EpetraVectorT as input arguments.");
    //      return getEpetra_Vector()->Dot(*tA.getEpetra_Vector());

    // other way: use the MultiVector Dot instead of VectorDot:
    double r;
    this->EpetraMultiVectorT<GlobalOrdinal, Node>::getEpetra_MultiVector()->Epetra_MultiVector::Dot(*tA.getEpetra_MultiVector(), &r);
    return r;
  }

  //! Return 1-norm of this Vector.
  Teuchos::ScalarTraits<Scalar>::magnitudeType norm1() const {
    XPETRA_MONITOR("EpetraVectorT::norm1");
    Scalar r;
    this->EpetraMultiVectorT<GlobalOrdinal, Node>::getEpetra_MultiVector()->Norm1(&r);
    return r;
  }

  //! Compute 2-norm of this Vector.
  Teuchos::ScalarTraits<Scalar>::magnitudeType norm2() const {
    XPETRA_MONITOR("EpetraVectorT::norm2");
    Scalar r;
    this->EpetraMultiVectorT<GlobalOrdinal, Node>::getEpetra_MultiVector()->Norm2(&r);
    return r;
  }

  //! Compute Inf-norm of this Vector.
  Teuchos::ScalarTraits<Scalar>::magnitudeType normInf() const {
    XPETRA_MONITOR("EpetraVectorT::normInf");
    Scalar r;
    this->EpetraMultiVectorT<GlobalOrdinal, Node>::getEpetra_MultiVector()->NormInf(&r);
    return r;
  }

  //! Compute Weighted 2-norm (RMS Norm) of this Vector.
  // Teuchos::ScalarTraits< Scalar >::magnitudeType normWeighted(const Vector< Scalar, LocalOrdinal, GlobalOrdinal, Node > &weights) const;

  //! Compute mean (average) value of this Vector.
  Scalar meanValue() const {
    XPETRA_MONITOR("EpetraVectorT::meanValue");
    Scalar r;
    this->EpetraMultiVectorT<GlobalOrdinal, Node>::getEpetra_MultiVector()->MeanValue(&r);
    return r;
  }

  //@}

  //! @name Overridden from Teuchos::Describable
  //@{

  //! Return a simple one-line description of this object.
  std::string description() const {
    XPETRA_MONITOR("EpetraVectorT::description");
    // This implementation come from Epetra_Vector_def.hpp (without modification)
    std::ostringstream oss;
    oss << Teuchos::Describable::description();
    oss << "{length=" << this->getGlobalLength()
        << "}";
    return oss.str();
  }

  //! Print the object with some verbosity level to an FancyOStream object.
  void describe(Teuchos::FancyOStream &out, const Teuchos::EVerbosityLevel verbLevel = Teuchos::Describable::verbLevel_default) const {
    XPETRA_MONITOR("EpetraVectorT::describe");

    if (verbLevel > Teuchos::VERB_NONE) {
      getEpetra_Vector()->Print(out);
    }
  }
  //@}

  //! @name Xpetra specific
  //@{

  //! EpetraMultiVectorT constructor to wrap a Epetra_Vector object
  EpetraVectorT(const Teuchos::RCP<Epetra_Vector> &vec)
    : EpetraMultiVectorT<GlobalOrdinal, Node>(vec) {}  // TODO: removed const of Epetra::Vector

  //! Get the underlying Epetra vector
  Epetra_Vector *getEpetra_Vector() const { return (*this->EpetraMultiVectorT<GlobalOrdinal, Node>::getEpetra_MultiVector())(0); }
  // RCP<Epetra_Vector> getEpetra_Vector() const { return this->EpetraMultiVectorT<GlobalOrdinal>::getEpetra_MultiVector()->getVectorNonConst(0); }

  //! This constructor creates a Vector which is a view of column j of the MultiVector 'mv'.
  //! It implements the logic of MultiVector::getVector/getVectorNonConst() for Epetra MultiVector.
  //! The newly created Xpetra::EpetraVectorT will remain valid after the disappearance of the references to 'mv' in user code.
  EpetraVectorT(const RCP<Epetra_MultiVector> &mv, size_t j)
    : EpetraMultiVectorT<GlobalOrdinal, Node>(rcp((*mv)(j), false))
    ,                         // view of the vector number j. false == I do not own the data.
    internalRefToBaseMV_(mv)  // keep an internal reference to the initial MultiVector to avoid desallocation of the view.
  {
    // The view of the internal data of 'mv' is only valid until the destruction of 'mv'.
    // The new vector hold an internal reference to 'mv' in order to keep the view valid after disappearance of 'mv' references in user code.
    // This implements the logic of subArray rcp (as required by the Tpetra interface).
  }

  //@}

 private:
  // This private member is only used by the constructor EpetraVectorT(const RCP<EpetraMultiVectorT<GlobalOrdinal> > &mv, size_t j). The actual private member holding the Epetra vector (vec_) is in the base class (Xpetra:EpetraMultiVectorT)
  const RCP<const Epetra_MultiVector> internalRefToBaseMV_;
};
#endif

// specialization on GO=long long and Node=Serial
#ifndef XPETRA_EPETRA_NO_64BIT_GLOBAL_INDICES
template <>
class EpetraVectorT<long long, EpetraNode>
  : public virtual Vector<double, int, long long, EpetraNode>, public EpetraMultiVectorT<long long, EpetraNode> {
  typedef double Scalar;
  typedef int LocalOrdinal;
  typedef long long GlobalOrdinal;
  typedef EpetraNode Node;

 public:
  using EpetraMultiVectorT<GlobalOrdinal, Node>::dot;                 // overloading, not hiding
  using EpetraMultiVectorT<GlobalOrdinal, Node>::norm1;               // overloading, not hiding
  using EpetraMultiVectorT<GlobalOrdinal, Node>::norm2;               // overloading, not hiding
  using EpetraMultiVectorT<GlobalOrdinal, Node>::normInf;             // overloading, not hiding
  using EpetraMultiVectorT<GlobalOrdinal, Node>::meanValue;           // overloading, not hiding
  using EpetraMultiVectorT<GlobalOrdinal, Node>::replaceGlobalValue;  // overloading, not hiding
  using EpetraMultiVectorT<GlobalOrdinal, Node>::sumIntoGlobalValue;  // overloading, not hiding
  using EpetraMultiVectorT<GlobalOrdinal, Node>::replaceLocalValue;   // overloading, not hiding
  using EpetraMultiVectorT<GlobalOrdinal, Node>::sumIntoLocalValue;   // overloading, not hiding

  //! @name Constructor/Destructor Methods
  //@{

  //! Sets all vector entries to zero.
  explicit EpetraVectorT(const Teuchos::RCP<const Map<int, GlobalOrdinal, Node> > &map, bool zeroOut = true)
    : EpetraMultiVectorT<GlobalOrdinal, Node>(map, 1, zeroOut) {}

  // Commenting out since no definition provided in cpp.
  //! Vector copy constructor.
  // EpetraVectorT(const Vector< Scalar, LocalOrdinal, GlobalOrdinal, Node > &source);

  //! Destructor.
  virtual ~EpetraVectorT() {}

  //@}

  //! @name Post-construction modification routines
  //@{

  //! Replace current value at the specified location with specified value.
  void replaceGlobalValue(GlobalOrdinal globalRow, const Scalar &value) {
    XPETRA_MONITOR("EpetraVectorT::replaceGlobalValue");
    this->EpetraMultiVectorT<GlobalOrdinal, Node>::getEpetra_MultiVector()->ReplaceGlobalValue(globalRow, 0, value);
  }

  //! Adds specified value to existing value at the specified location.
  void sumIntoGlobalValue(GlobalOrdinal globalRow, const Scalar &value) {
    XPETRA_MONITOR("EpetraVectorT::sumIntoGlobalValue");
    this->EpetraMultiVectorT<GlobalOrdinal, Node>::getEpetra_MultiVector()->SumIntoGlobalValue(globalRow, 0, value);
  }

  //! Replace current value at the specified location with specified values.
  void replaceLocalValue(LocalOrdinal myRow, const Scalar &value) {
    XPETRA_MONITOR("EpetraVectorT::replaceLocalValue");
    this->EpetraMultiVectorT<GlobalOrdinal, Node>::getEpetra_MultiVector()->ReplaceMyValue(myRow, 0, value);
  }

  //! Adds specified value to existing value at the specified location.
  void sumIntoLocalValue(LocalOrdinal myRow, const Scalar &value) {
    XPETRA_MONITOR("EpetraVectorT::sumIntoLocalValue");
    this->EpetraMultiVectorT<GlobalOrdinal, Node>::getEpetra_MultiVector()->SumIntoMyValue(myRow, 0, value);
  }

  //@}

  //! @name Mathematical methods
  //@{

  //! Computes dot product of this Vector against input Vector x.
  Scalar dot(const Vector<Scalar, LocalOrdinal, GlobalOrdinal, Node> &a) const {
    XPETRA_MONITOR("EpetraVectorT::dot");

    XPETRA_DYNAMIC_CAST(const EpetraVectorT, a, tA, "This Xpetra::EpetraVectorT method only accept Xpetra::EpetraVectorT as input arguments.");
    //      return getEpetra_Vector()->Dot(*tA.getEpetra_Vector());

    // other way: use the MultiVector Dot instead of VectorDot:
    double r;
    this->EpetraMultiVectorT<GlobalOrdinal, Node>::getEpetra_MultiVector()->Epetra_MultiVector::Dot(*tA.getEpetra_MultiVector(), &r);
    return r;
  }

  //! Return 1-norm of this Vector.
  Teuchos::ScalarTraits<Scalar>::magnitudeType norm1() const {
    XPETRA_MONITOR("EpetraVectorT::norm1");
    Scalar r;
    this->EpetraMultiVectorT<GlobalOrdinal, Node>::getEpetra_MultiVector()->Norm1(&r);
    return r;
  }

  //! Compute 2-norm of this Vector.
  Teuchos::ScalarTraits<Scalar>::magnitudeType norm2() const {
    XPETRA_MONITOR("EpetraVectorT::norm2");
    Scalar r;
    this->EpetraMultiVectorT<GlobalOrdinal, Node>::getEpetra_MultiVector()->Norm2(&r);
    return r;
  }

  //! Compute Inf-norm of this Vector.
  Teuchos::ScalarTraits<Scalar>::magnitudeType normInf() const {
    XPETRA_MONITOR("EpetraVectorT::normInf");
    Scalar r;
    this->EpetraMultiVectorT<GlobalOrdinal, Node>::getEpetra_MultiVector()->NormInf(&r);
    return r;
  }

  //! Compute Weighted 2-norm (RMS Norm) of this Vector.
  // Teuchos::ScalarTraits< Scalar >::magnitudeType normWeighted(const Vector< Scalar, LocalOrdinal, GlobalOrdinal, Node > &weights) const;

  //! Compute mean (average) value of this Vector.
  Scalar meanValue() const {
    XPETRA_MONITOR("EpetraVectorT::meanValue");
    Scalar r;
    this->EpetraMultiVectorT<GlobalOrdinal, Node>::getEpetra_MultiVector()->MeanValue(&r);
    return r;
  }

  //@}

  //! @name Overridden from Teuchos::Describable
  //@{

  //! Return a simple one-line description of this object.
  std::string description() const {
    XPETRA_MONITOR("EpetraVectorT::description");
    // This implementation come from Epetra_Vector_def.hpp (without modification)
    std::ostringstream oss;
    oss << Teuchos::Describable::description();
    oss << "{length=" << this->getGlobalLength()
        << "}";
    return oss.str();
  }

  //! Print the object with some verbosity level to an FancyOStream object.
  void describe(Teuchos::FancyOStream &out, const Teuchos::EVerbosityLevel verbLevel = Teuchos::Describable::verbLevel_default) const {
    XPETRA_MONITOR("EpetraVectorT::describe");

    if (verbLevel > Teuchos::VERB_NONE) {
      getEpetra_Vector()->Print(out);
    }
  }
  //@}

  //! @name Xpetra specific
  //@{

  //! EpetraMultiVectorT constructor to wrap a Epetra_Vector object
  EpetraVectorT(const Teuchos::RCP<Epetra_Vector> &vec)
    : EpetraMultiVectorT<GlobalOrdinal, Node>(vec) {}  // TODO: removed const of Epetra::Vector

  //! Get the underlying Epetra vector
  Epetra_Vector *getEpetra_Vector() const { return (*this->EpetraMultiVectorT<GlobalOrdinal, Node>::getEpetra_MultiVector())(0); }
  // RCP<Epetra_Vector> getEpetra_Vector() const { return this->EpetraMultiVectorT<GlobalOrdinal>::getEpetra_MultiVector()->getVectorNonConst(0); }

  //! This constructor creates a Vector which is a view of column j of the MultiVector 'mv'.
  //! It implements the logic of MultiVector::getVector/getVectorNonConst() for Epetra MultiVector.
  //! The newly created Xpetra::EpetraVectorT will remain valid after the disappearance of the references to 'mv' in user code.
  EpetraVectorT(const RCP<Epetra_MultiVector> &mv, size_t j)
    : EpetraMultiVectorT<GlobalOrdinal, Node>(rcp((*mv)(j), false))
    ,                         // view of the vector number j. false == I do not own the data.
    internalRefToBaseMV_(mv)  // keep an internal reference to the initial MultiVector to avoid desallocation of the view.
  {
    // The view of the internal data of 'mv' is only valid until the destruction of 'mv'.
    // The new vector hold an internal reference to 'mv' in order to keep the view valid after disappearance of 'mv' references in user code.
    // This implements the logic of subArray rcp (as required by the Tpetra interface).
  }

  //@}

 private:
  // This private member is only used by the constructor EpetraVectorT(const RCP<EpetraMultiVectorT<GlobalOrdinal> > &mv, size_t j). The actual private member holding the Epetra vector (vec_) is in the base class (Xpetra:EpetraMultiVectorT)
  const RCP<const Epetra_MultiVector> internalRefToBaseMV_;
};
#endif

}  // namespace Xpetra

#endif  // XPETRA_EPETRAVECTOR_HPP
