#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const long long mod=998244353;

int main(){
  int64_t N,K,S;
  cin>>N>>K>>S;
  vector<int>ans(N);
  int cnt=K;
  for(int i=0;i<N;i++){
    if(cnt>0){cnt--;ans[i]=S;}
    else{
      if(S==1000000000){ans[i]=1;}
      else{ans[i]=1000000000;}
    }
  }
  for(int i=0;i<N;i++){
    cout<<ans[i]<<" ";
  }cout<<endl;
  return 0;                       
}