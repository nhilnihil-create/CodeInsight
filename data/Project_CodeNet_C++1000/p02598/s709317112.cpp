#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <cmath>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int mod=1e9+7;
const int64_t INF=1e18;
int64_t N,K;
int64_t A[1000005];
int64_t f(int64_t m){
  int cnt=0;
  for(int i=0;i<N;i++){
    if(A[i]>m){cnt+=(A[i]-1)/m;}
  }
  return cnt;
}
int main() {
  cin>>N>>K;
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  
  int64_t l=0,r=1e9+1;
  while(r-l>1){
    int64_t m=(r+l)/2;//m=max長さ
    if(f(m)<=K){r=m;}//K回以内でｍ以内の長さにできる長さの範囲＝ｒ
    if(f(m)>K){l=m;}
  }
  cout<<r<<endl;
  return 0;  
}