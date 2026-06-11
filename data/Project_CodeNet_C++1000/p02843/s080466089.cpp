#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;

int main() {
  int x;
  cin>>x;
  for(int i=0;i<=1000;i++){
   if(x>=100*i&&x<=105*i){cout<<1<<endl;return 0;}
  }
  cout<<0<<endl;
  return 0;
}