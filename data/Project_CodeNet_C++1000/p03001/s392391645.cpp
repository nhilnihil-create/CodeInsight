#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1e9+7;
const int INF=1001001001;

int main() {
  double W,H,x,y;
  cin>>W>>H>>x>>y;
  int a=0;
  if(x==W/2&&y==H/2){a=1;}
  cout<<W*H/2<<" "<<a<<endl;
  return 0;  
}