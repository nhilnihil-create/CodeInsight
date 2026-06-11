#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <type_traits>
#include <vector>

// lib/detail/ceil_and_floor.hpp
#ifndef DETAIL_CEIL_AND_FLOOR_HPP
#define DETAIL_CEIL_AND_FLOOR_HPP

namespace tools {
  template <typename T>
  constexpr T floor(T lhs, T rhs);

  template <typename T>
  constexpr T ceil(T lhs, T rhs);

  template <typename T>
  constexpr T floor(const T lhs, const T rhs) {
    return
      lhs >= 0 && rhs >= 0 ?
        lhs / rhs :
      lhs < 0 && rhs >= 0 ?
        -ceil<T>(-lhs, rhs) :
      lhs >= 0 && rhs < 0 ?
        -ceil<T>(lhs, -rhs) :
        floor<T>(-lhs, -rhs);
  }

  template <typename T>
  constexpr T ceil(const T lhs, const T rhs) {
    return
      lhs >= 0 && rhs >= 0 ?
        (lhs - 1 + rhs) / rhs :
      lhs < 0 && rhs >= 0 ?
        -floor<T>(-lhs, rhs) :
      lhs >= 0 && rhs < 0 ?
        -floor<T>(lhs, -rhs) :
        ceil<T>(-lhs, -rhs);
  }
}

#endif

// lib/signum.hpp
#ifndef SIGNUM_HPP
#define SIGNUM_HPP


/*
usage:

tools::signum(-5) // => -1
*/

namespace tools {
  template <typename T>
  constexpr int signum(const T x, const std::false_type) noexcept {
    return T(0) < x;
  }

  template <typename T>
  constexpr int signum(const T x, const std::true_type) noexcept {
    return (T(0) < x) - (x < T(0));
  }

  template <typename T>
  constexpr int signum(const T x) noexcept {
    return signum(x, std::is_signed<T>());
  }
}

#endif

// lib/util.hpp
#ifndef UTIL_HPP
#define UTIL_HPP


typedef ::std::int_fast64_t i64;
typedef ::std::uint_fast64_t u64;
typedef ::std::int_fast32_t i32;
typedef ::std::uint_fast32_t u32;

namespace tools {
  template <typename T>
  void read(::std::istream& is, ::std::vector<T>& vector, const typename ::std::vector<T>::size_type size) {
    vector.reserve(size);
    ::std::copy_n(::std::istream_iterator<T>(is), size, ::std::back_inserter(vector));
  }
  template <typename T>
  void read(::std::vector<T>& vector, const typename ::std::vector<T>::size_type size) {
    ::tools::read(::std::cin, vector, size);
  }

  template <typename T, ::std::size_t N>
  void read(::std::istream& is, ::std::array<T, N>& array) {
    ::std::copy_n(std::istream_iterator<T>(is), N, array.begin());
  }
  template <typename T, ::std::size_t N>
  void read(::std::array<T, N>& array) {
    ::tools::read(::std::cin, array);
  }
}

#endif

// lib/floor.hpp
#ifndef FLOOR_HPP
#define FLOOR_HPP


/*
usage:

tools::floor(5, 3) // => 1 (i.e., floor(5 / 3))
*/

#endif

// lib/ceil.hpp
#ifndef CEIL_HPP
#define CEIL_HPP


/*
usage:

tools::ceil(5, 3) // => 2 (i.e., ceil(5 / 3))
*/

#endif

// main.cpp

int main() {
  i64 T1, T2, A1, A2, B1, B2;
  std::cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;

  const i64 delta1 = T1 * (B1 - A1);
  const i64 delta2 = T2 * (B2 - A2);

  if (tools::signum(delta1) * tools::signum(delta2) > 0) {
    std::cout << 0 << std::endl;
  } else {
    if (std::abs(delta1) > std::abs(delta2)) {
      std::cout << 0 << std::endl;
    } else if (std::abs(delta1) == std::abs(delta2)) {
      std::cout << "infinity" << std::endl;
    } else {
      const i64 floor = tools::floor(-delta1, delta1 + delta2);
      const i64 ceil = tools::ceil(-delta1, delta1 + delta2);
      std::cout << 2 * floor + (ceil - floor) << std::endl;
    }
  }

  return 0;
}