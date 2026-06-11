#include <bits/stdc++.h>
using namespace std;

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
using namespace boost::multiprecision;

using bint = cpp_int;
using bdec = cpp_dec_float_100;
// using bdec = number<cpp_dec_float<10000>>;

int main() {
  bint N;
  cin >> N;
  cout << ((N % 9) ? "No" : "Yes") << "\n";
}