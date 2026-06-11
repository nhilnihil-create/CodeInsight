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

class operation {
public:
  i64 x, y;
  operation(const i64 x, const i64 y) :
    x(x), y(y) {
  }
  i64 result() const {
    return this->x - this->y;
  }
};

int main() {
  i64 N;
  std::cin >> N;
  std::vector<i64> A;
  tools::read(A, N);

  std::vector<operation> operations;
  if (std::count_if(A.begin(), A.end(), [](const i64& A_i) { return A_i < 0; }) <= 1) {
    const auto min_it = std::min_element(A.begin(), A.end());
    const i64 min_A_i = *min_it;
    A.erase(min_it);

    if (N == 2) {
      operations.emplace_back(A[0], min_A_i);
    } else {
      operations.emplace_back(min_A_i, A[0]);
      for (i64 i = 1; i <= N - 3; ++i) {
        operations.emplace_back(operations.back().result(), A[i]);
      }
      operations.emplace_back(A.back(), operations.back().result());
    }
  } else if (std::count_if(A.begin(), A.end(), [](const i64& A_i) { return A_i > 0; }) <= 1) {
    const auto max_it = std::max_element(A.begin(), A.end());
    const i64 max_A_i = *max_it;
    A.erase(max_it);

    operations.emplace_back(max_A_i, A[0]);
    for (i64 i = 1; i <= N - 2; ++i) {
      operations.emplace_back(operations.back().result(), A[i]);
    }
  } else {
    std::vector<i64> positives;
    std::copy_if(A.begin(), A.end(), std::back_inserter(positives), [](const i64& A_i) { return A_i >= 0; });
    std::vector<i64> negatives;
    std::copy_if(A.begin(), A.end(), std::back_inserter(negatives), [](const i64& A_i) { return A_i < 0; });

    operations.emplace_back(positives[0], negatives[1]);
    for (i64 i = 2; i < static_cast<i64>(negatives.size()); ++i) {
      operations.emplace_back(operations.back().result(), negatives[i]);
    }
    const i64 lhs = operations.back().result();

    operations.emplace_back(negatives[0], positives[1]);
    for (i64 i = 2; i < static_cast<i64>(positives.size()); ++i) {
      operations.emplace_back(operations.back().result(), positives[i]);
    }
    const i64 rhs = operations.back().result();

    operations.emplace_back(lhs, rhs);
  }

  std::cout << operations.back().result() << std::endl;
  for (const operation& operation : operations) {
    std::cout << operation.x << ' ' << operation.y << std::endl;
  }
  return 0;
}