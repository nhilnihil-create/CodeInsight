#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <utility>
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

// lib/union_find.hpp
#ifndef UNION_FIND_HPP
#define UNION_FIND_HPP


/*
usage:

tools::union_find<std::int_fast64_t> uf(10);
uf.unite(1, 3);
uf.is_same(1, 3);
*/

namespace tools {
  template <typename T>
  class union_find {
  private:
    std::vector<T> parents;
    std::vector<T> sizes;
    T component_count;

  public:
    union_find(const T n) :
      parents(n),
      sizes(n, 1),
      component_count(n) {
      for (T i = 0; i < n; ++i) {
        parents[i] = i;
      }
    }

    T root(const T x) {
      return this->parents[x] == x ? x : (this->parents[x] = this->root(this->parents[x]));
    }

    bool is_same(const T x, const T y) {
      return this->root(x) == this->root(y);
    }

    void unite(T x, T y) {
      x = this->root(x);
      y = this->root(y);
      if (x == y) return;

      if (this->sizes[x] < this->sizes[y]) std::swap(x, y);
      this->parents[y] = x;
      this->sizes[x] += this->sizes[y];
      --this->component_count;
    }

    T size() const {
      return this->component_count;
    }

    T size(const T x) {
      return this->sizes[this->root(x)];
    }
  };
}

#endif

// main.cpp

int main() {
  i64 N, K;
  std::cin >> N >> K;
  std::vector<i64> P, C;
  tools::read(P, N);
  for (i64& P_i : P) --P_i;
  tools::read(C, N);

  std::vector<std::vector<i64>> components;
  {
    std::vector<bool> visited(N, false);
    for (i64 i = 0; i < N; ++i) {
      if (!visited[i]) {
        components.emplace_back();
        for (i64 j = i; !visited[j]; j = P[j]) {
          components.back().push_back(j);
          visited[j] = true;
        }
      }
    }
  }

  i64 answer = std::numeric_limits<i64>::min();
  for (const std::vector<i64>& component : components) {
    const i64 period = component.size();

    std::vector<i64> cumsum({0});
    for (const i64& i : component) {
      cumsum.push_back(cumsum.back() + C[i]);
    }
    for (const i64& i : component) {
      cumsum.push_back(cumsum.back() + C[i]);
    }

    const i64 unit = std::max<i64>(0, cumsum[period] - cumsum[0]);

    for (i64 i = 0; i < period; ++i) {
      for (i64 j = i + 1; j <= i + std::min(period, K); ++j) {
        answer = std::max(answer, cumsum[j] - cumsum[i] + (K - (j - i)) / period * unit);
      }
    }
  }

  std::cout << answer << std::endl;
  return 0;
}