#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;

int main() {
  double W,H,x,y;
  cin>>W>>H>>x>>y;
  cout<<fixed<<setprecision(9)<<W*H/2<<endl;
  if(x==W/2&&y==H/2){cout<<1<<endl;}
  else{cout<<0<<endl;}
  return 0;  
}