#include <bits/stdc++.h>
#include <boost/integer/common_factor_rt.hpp>
using namespace std;
using ll=long long;

int main() {
  ll a,b,c;
  cin >> a >> b >> c;
  if(a+b>=c)
  cout << "No" << endl;
  else{
    if(2*powl(a*b,0.5)<c-a-b)
    cout << "Yes" << endl;
    else
    cout << "No" << endl;
  }
}

