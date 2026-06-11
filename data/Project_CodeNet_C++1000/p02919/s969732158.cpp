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

constexpr i64 N_A = std::numeric_limits<i64>::max();

class state {
public:
  i64 l2, l1, c, r1, r2;
};

int main() {
  i64 N;
  std::cin >> N;
  std::vector<std::pair<i64, i64>> P;
  for (i64 i = 0; i < N; ++i) {
    i64 P_i;
    std::cin >> P_i;
    P.push_back(std::make_pair(P_i, i));
  }
  std::sort(P.begin(), P.end(), std::greater<std::pair<i64, i64>>());
  std::set<i64> set;
  std::vector<state> status(N);
  for (const std::pair<i64, i64>& pair : P) {
    const auto it = set.insert(pair.second).first;
    const i64 c = pair.second;

    auto l_it = it;
    i64 l1, l2;
    if (l_it == set.begin()) {
      l1 = N_A;
      l2 = -1;
    } else {
      --l_it;
      if (l_it == set.begin()) {
        l1 = *l_it;
        l2 = -1;
      } else {
        l1 = *l_it;
        --l_it;
        l2 = *l_it;
      }
    }

    auto r_it = it;
    i64 r1, r2;
    ++r_it;
    if (r_it == set.end()) {
      r1 = N_A;
      r2 = N;
    } else {
      r1 = *r_it;
      ++r_it;
      if (r_it == set.end()) {
        r2 = N;
      } else {
        r2 = *r_it;
      }
    }

    status[pair.first - 1].l2 = l2;
    status[pair.first - 1].l1 = l1;
    status[pair.first - 1].c = c;
    status[pair.first - 1].r1 = r1;
    status[pair.first - 1].r2 = r2;
  }

  i64 answer = 0;
  for (i64 i = 0; i < N; ++i) {
    if (status[i].l1 != N_A) {
      answer += (i + 1) * (status[i].l1 - status[i].l2) * ((status[i].r1 == N_A ? status[i].r2 : status[i].r1) - status[i].c);
    }
    if (status[i].r1 != N_A) {
      answer += (i + 1) * (status[i].r2 - status[i].r1) * (status[i].c - (status[i].l1 == N_A ? status[i].l2 : status[i].l1));
    }
  }
  std::cout << answer << std::endl;
  return 0;
}