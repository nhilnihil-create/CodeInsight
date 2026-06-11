#include <bits/stdc++.h>
using namespace std;

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
using namespace boost::multiprecision;

using ci = cpp_int;
using cd = number<cpp_dec_float<10000>>;

int main() {
  cd a, b, c;
  cin >> a >> b >> c;
  cout << ((sqrt(a) + sqrt(b) < sqrt(c)) ? "Yes" : "No") << "\n";
}