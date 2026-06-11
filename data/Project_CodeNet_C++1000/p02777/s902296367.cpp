#include <bits/stdc++.h>
#include <boost/integer/common_factor_rt.hpp>
using namespace std;
using ll=long long;
const int MOD=1000000007;


int main() {
  string s,t;
  cin >> s >> t;
  int a,b;
  cin >> a >> b;
  string u;
  cin >> u;
  if(s==u)
  cout << a-1 << " " << b << endl;
  else
  cout << a << " " << b-1 << endl;
}