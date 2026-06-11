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
  i64 N, K, C;
  std::string S;
  std::cin >> N >> K >> C >> S;

  std::vector<i64> from_left;
  from_left.reserve(K);
  for (i64 i = 0; i < N;) {
    if (S[i] == 'o') {
      if (static_cast<i64>(from_left.size()) >= K) return 0;
      from_left.push_back(i);
      i += C + 1;
    } else {
      ++i;
    }
  }

  std::vector<i64> from_right;
  from_right.reserve(K);
  for (i64 i = N - 1; i >= 0;) {
    if (S[i] == 'o') {
      from_right.push_back(i);
      i -= C + 1;
    } else {
      --i;
    }
  }
  std::reverse(from_right.begin(), from_right.end());

  for (i64 i = 0; i < K; ++i) {
    if (from_left[i] == from_right[i]) {
      std::cout << from_left[i] + 1 << std::endl;
    }
  }
  return 0;
}