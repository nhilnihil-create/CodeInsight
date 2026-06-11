#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_dec_float.hpp>
using namespace std;
using namespace boost::multiprecision;

int main() {
  cpp_dec_float_100 a, b, c;
  cin >> a >> b >> c;
  cout << ((sqrt(a) + sqrt(b) < sqrt(c)) ? "Yes" : "No") << "\n";
}