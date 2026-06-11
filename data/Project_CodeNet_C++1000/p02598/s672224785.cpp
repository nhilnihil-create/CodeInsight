#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;

int N,K;
vector<int>A;
bool f(int x){
  int cnt=0;
  for(int i=0;i<N;i++){
    cnt+=(A[i]-1)/x;
  }
  if(cnt<=K){return true;}
  else{return false;}
}

int main() {
  cin>>N>>K;
  A.resize(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  int l=0,r=1e9+1;
  while(r-l>1){
    int mid=(l+r)/2;
    if(f(mid)){r=mid;}
    else{l=mid;}
  }
  cout<<r<<endl;
  return 0;  
}