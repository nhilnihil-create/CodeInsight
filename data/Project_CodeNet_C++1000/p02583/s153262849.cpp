#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <vector>

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

// main.cpp

int main() {
  i64 N;
  std::cin >> N;
  std::vector<i64> L;
  tools::read(L, N);

  i64 answer = 0;
  for (i64 i = 0; i < N - 2; ++i) {
    for (i64 j = i + 1; j < N - 1; ++j) {
      for (i64 k = j + 1; k < N; ++k) {
        if (L[i] != L[j] && L[j] != L[k] && L[k] != L[i] && L[i] + L[j] > L[k] && L[j] + L[k] > L[i] && L[k] + L[i] > L[j]) {
          ++answer;
        }
      }
    }
  }

  std::cout << answer << std::endl;
  return 0;
}