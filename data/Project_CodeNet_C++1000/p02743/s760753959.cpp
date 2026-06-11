#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <cmath>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int mod=1e9+7;
const int64_t INF=1e18;

int main() {
  int64_t a,b,c;
  cin>>a>>b>>c;
  if(c-a-b>0&&(c-a-b)*(c-a-b)>4*a*b){cout<<"Yes"<<endl;}
  else{cout<<"No"<<endl;}
  return 0;  
}