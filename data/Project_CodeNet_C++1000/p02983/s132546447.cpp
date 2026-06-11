#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const int mod=1e9+7;

int main(){
  int64_t L,R;
  cin>>L>>R;
  int64_t sum=1e18;
  int64_t t=L+2019*2;
  for(int i=L;i<=min(t,R);i++){
    for(int j=i+1;j<=min(t,R);j++){
      int l=i%2019,r=j%2019;
      int64_t x=l*r;x%=2019;
      chmin(sum,x);
    }
  }
  cout<<sum<<endl;
  return 0;
}