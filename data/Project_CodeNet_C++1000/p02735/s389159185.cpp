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
  i64 H, W;
  std::cin >> H >> W;
  std::vector<std::string> s;
  tools::read(s, H);

  std::vector<std::vector<i64>> dp(H, std::vector<i64>(W, std::numeric_limits<i64>::max()));
  dp[0][0] = s[0][0] == '#' ? 1 : 0;
  for (i64 i = 0; i < H; ++i) {
    for (i64 j = 0; j < W; ++j) {
      if (i + 1 < H) {
        dp[i + 1][j] = std::min(dp[i + 1][j], dp[i][j] + (s[i][j] == '.' && s[i + 1][j] == '#' ? 1 : 0));
      }
      if (j + 1 < W) {
        dp[i][j + 1] = std::min(dp[i][j + 1], dp[i][j] + (s[i][j] == '.' && s[i][j + 1] == '#' ? 1 : 0));
      }
    }
  }

  std::cout << dp[H - 1][W - 1] << std::endl;
  return 0;
}