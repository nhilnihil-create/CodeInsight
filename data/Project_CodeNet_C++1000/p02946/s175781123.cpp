#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const int mod=1e9+7;

int main() {
  int K,X;
  cin>>K>>X;
  for(int i=X-K+1;i<=X+K-1;i++){
    cout<<i;
    if(i<X+K-1){cout<<" ";}
  }cout<<endl;
  return 0;
}