#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_bin_float.hpp>
using namespace std;
using namespace boost::multiprecision;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  cpp_bin_float_100 a, b, c, eps(1e-80);
  cin >> a >> b >> c;
  
  if (sqrt(c) - sqrt(a) - sqrt(b) > eps) cout << "Yes\n";
  else cout << "No\n";
}