#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
  #include "_DEBUG.hpp"
#endif
#define int long long
const int INF = 1LL << 60;

#define double long double //大正義!!!

signed main(){

  int a, b, c; cin >> a >> b >> c;

  int d = c - a - b;
  if(d <= 0){
    cout << "No" << endl;
    return 0;
  }
  if(4*a*b < d*d){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }

  return 0;
}