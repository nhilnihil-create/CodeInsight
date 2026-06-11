#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <vector>

// lib/quo.hpp
#ifndef QUO_H
#define QUO_H

/*
a == tools::quo(a, b) * b + tools::mod(a, b)
0 <= tools::mod(a, b) < std::abs(b)
*/

namespace tools {
  template <typename T>
  constexpr T quo(const T& lhs, const T& rhs) {
    return lhs > static_cast<T>(0)
      ? lhs / rhs
      : rhs > static_cast<T>(0)
        ? -((-lhs - 1 + rhs) / rhs)
        : (-lhs - 1 + -rhs) / -rhs;
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

// lib/mod.hpp
#ifndef MOD_HPP
#define MOD_HPP


/*
a == tools::quo(a, b) * b + tools::mod(a, b)
0 <= tools::mod(a, b) < std::abs(b)
*/

namespace tools {
  template <typename T>
  constexpr T mod(const T& lhs, const T& rhs) {
    return lhs - ::tools::quo(lhs, rhs) * rhs;
  }
}

#endif

// main.cpp

int main() {
  i64 X, K, D;
  std::cin >> X >> K >> D;

  if (tools::quo(X, D) >= K) {
    std::cout << X - K * D << std::endl;
    return 0;
  }

  if (tools::quo(-X, D) >= K) {
    std::cout << -X - K * D << std::endl;
    return 0;
  }

  i64 answer = tools::mod(tools::mod(X, 2 * D) + tools::mod<i64>(K, 2) * D, 2 * D);
  if (answer > D) answer = 2 * D - answer;
  std::cout << answer << std::endl;
  return 0;
}