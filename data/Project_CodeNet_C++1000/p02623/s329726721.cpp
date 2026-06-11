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
  i64 N, M, K;
  std::cin >> N >> M >> K;
  std::vector<i64> A, B;
  tools::read(A, N);
  tools::read(B, M);

  std::vector<i64> A_cumsum({0});
  std::partial_sum(A.begin(), A.end(), std::back_inserter(A_cumsum));
  std::vector<i64> B_cumsum({0});
  std::partial_sum(B.begin(), B.end(), std::back_inserter(B_cumsum));

  // 合計所要時間がK分を超えないようにx冊読めるような本の選び方が存在するか
  const auto f = [&](const i64& x) {
    for (i64 i = std::max<i64>(0, x - M); i <= std::min(x, N); ++i) {
      if (A_cumsum[i] + B_cumsum[x - i] <= K) {
        return true;
      }
    }
    return false;
  };

  i64 ok = 0;
  i64 ng = N + M + 1;
  while (ng - ok > 1) {
    i64 center = (ok + ng) / 2;
    if (f(center)) {
      ok = center;
    } else {
      ng = center;
    }
  }

  std::cout << ok << std::endl;
  return 0;
}