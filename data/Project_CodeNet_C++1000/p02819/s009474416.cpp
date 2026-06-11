#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1e9+7;
const int INF=1001001001;

int main() {
  int x;
  cin>>x;
  for(int i=x;i<=x+10000;i++){
    bool ok=true;
    for(int j=2;j*j<=i;j++){
      if(i%j==0){ok=false;}
    }
    if(ok){cout<<i<<endl;return 0;}
  }
  return 0;  
}