#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>

// lib/less_by.hpp
#ifndef LESS_BY_HPP
#define LESS_BY_HPP


/*
usage:

std::sort(a.begin(), a.end(), tools::less_by([](int a_i) { return std::abs(x); }));
*/

namespace tools {
  template <class T, class R>
  class less_by {
  private:
    ::std::function<R(T)> selector;

  public:
    less_by(const ::std::function<R(T)>& selector) : selector(selector) {
    }

    bool operator()(const T& x, const T& y) const {
      return selector(x) < selector(y);
    }

    using first_argument_type = T;
    using second_argument_type = T;
    using result_type = bool;
  };
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

class robot {
public:
  i64 X;
  i64 L;
  friend std::istream& operator>>(std::istream& is, robot& self) {
    return is >> self.X >> self.L;
  }
};

int main() {
  i64 N;
  std::cin >> N;
  std::vector<robot> robots;
  tools::read(robots, N);

  std::sort(robots.begin(), robots.end(), tools::less_by<robot, i64>([](const robot& robot) { return robot.X + robot.L; }));
  i64 max = std::numeric_limits<i64>::min();
  i64 answer = 0;
  for (const robot& robot : robots) {
    if (max <= robot.X - robot.L) {
      max = robot.X + robot.L;
      ++answer;
    }
  }

  std::cout << answer << std::endl;
  return 0;
}