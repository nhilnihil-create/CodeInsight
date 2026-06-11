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
  i64 N;
  std::cin >> N;
  std::vector<i64> A;
  tools::read(A, N + 1);

  std::vector<std::pair<i64, i64>> inner_node_ranges;
  std::vector<std::pair<i64, i64>> before_breeding;
  {
    std::pair<i64, i64> range(1, 1);
    for (i64 i = 0; i < N; ++i) {
      range = std::make_pair(range.first - A[i], range.second - A[i]);
      if (range.second < 0) goto FAILURE;
      range = std::make_pair(std::max<i64>(0, range.first), range.second);
      before_breeding.push_back(range);
      range = std::make_pair(range.first, std::min<i64>(range.second * 2, 10000000000000));
    }
    range = std::make_pair(range.first - A[N], range.second - A[N]);
    if (range.second < 0 || 0 < range.first) goto FAILURE;

    auto it = before_breeding.rbegin();
    range = std::make_pair(A[N], A[N]);
    for (i64 i = N - 1; i >= 0; --i) {
      range = std::make_pair(tools::ceil<i64>(range.first, 2), range.second);
      range = std::make_pair(std::max(it->first, range.first), std::min(it->second, range.second));
      ++it;
      inner_node_ranges.push_back(range);
      range = std::make_pair(range.first + A[i], range.second + A[i]);
    }
    std::reverse(inner_node_ranges.begin(), inner_node_ranges.end());
  }

#ifdef DEBUG
  for (i64 i = 0; i < N; ++i) {
    std::cerr << '[' << inner_node_ranges[i].first + A[i] << ", " << inner_node_ranges[i].second + A[i] << "] = [" << inner_node_ranges[i].first << ", " << inner_node_ranges[i].second << "] + " << A[i] << std::endl;
  }
  std::cerr << '[' << A[N] << ", " << A[N] << "] = [0, 0] + " << A[N] << std::endl;
#endif

  std::cout << std::accumulate(
    inner_node_ranges.begin(),
    inner_node_ranges.end(),
    static_cast<i64>(0),
    [&](const i64& sum, const std::pair<i64, i64>& range) {
      return sum + range.second;
    }
  ) + std::accumulate(
    A.begin(),
    A.end(),
    static_cast<i64>(0)
  ) << std::endl;
  return 0;

FAILURE:
#ifdef DEBUG
  if ((before_breeding.empty() ? 1 : before_breeding.back().second * 2) - A[before_breeding.size()] < 0) {
    for (i64 i = 0; i < static_cast<i64>(before_breeding.size()); ++i) {
      std::cerr << before_breeding[i].second + A[i] << " = " << before_breeding[i].second << " + " << A[i] << std::endl;
    }
    std::cerr << (before_breeding.empty() ? 1 : before_breeding.back().second * 2) << " = " << (before_breeding.empty() ? 1 : before_breeding.back().second * 2) - A[before_breeding.size()] << " + " << A[before_breeding.size()] << std::endl;
  } else {
    for (i64 i = 0; i < static_cast<i64>(before_breeding.size()); ++i) {
      std::cerr << before_breeding[i].first + A[i] << " = " << before_breeding[i].first << " + " << A[i] << std::endl;
    }
    std::cerr << (before_breeding.empty() ? 1 : before_breeding.back().first) << " = " << (before_breeding.empty() ? 1 : before_breeding.back().first) - A[before_breeding.size()] << " + " << A[before_breeding.size()] << std::endl;
  }
#endif

  std::cout << -1 << std::endl;
  return 0;
}