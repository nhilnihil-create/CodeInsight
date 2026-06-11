#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

// lib/join.hpp
#ifndef JOIN_HPP
#define JOIN_HPP


namespace tools {
  template <typename Iterator>
  std::string join(const Iterator begin, const Iterator end, const std::string delimiter) {
    std::ostringstream ss;
    std::string current_delimiter = "";
    for (Iterator it = begin; it != end; ++it) {
      ss << current_delimiter << *it;
      current_delimiter = delimiter;
    }
    return ss.str();
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

// main.cpp

int main() {
  i64 N, K, S;
  std::cin >> N >> K >> S;

  std::vector<i64> A;
  A.reserve(N);
  for (i64 i = 0; i < K; ++i) {
    A.push_back(S);
  }
  for (i64 i = 0; i < N - K; ++i) {
    A.push_back(S < 1000000000 ? 1000000000 : 999999999);
  }

  std::cout << tools::join(A.begin(), A.end(), " ") << std::endl;
  return 0;
}