#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <vector>

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

// main.cpp

int main() {
  i64 A, B, M;
  std::cin >> A >> B >> M;
  std::vector<i64> a, b;
  tools::read(a, A);
  tools::read(b, B);

  i64 answer = *std::min_element(a.begin(), a.end()) + *std::min_element(b.begin(), b.end());
  for (i64 i = 0; i < M; ++i) {
    i64 x_i, y_i, c_i;
    std::cin >> x_i >> y_i >> c_i;
    --x_i;
    --y_i;
    answer = std::min(answer, a[x_i] + b[y_i] - c_i);
  }

  std::cout << answer << std::endl;
  return 0;
}