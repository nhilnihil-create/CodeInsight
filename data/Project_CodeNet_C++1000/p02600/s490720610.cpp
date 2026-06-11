#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <iostream>
#include <iterator>
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

// lib/util.hpp
#ifndef UTIL_HPP
#define UTIL_HPP


using i64 = ::std::int_fast64_t;
using u64 = ::std::uint_fast64_t;
using i32 = ::std::int_fast32_t;
using u32 = ::std::uint_fast32_t;

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
  i64 X;
  std::cin >> X;
  std::cout << tools::ceil<i64>(2000 - X, 200) << std::endl;
  return 0;
}