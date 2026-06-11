#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1e9+7;
const int INF=1001001001;

int main() {
  int64_t N,K;
  cin>>N>>K;
  vector<int64_t>P(N),C(N);
  for(int i=0;i<N;i++){
    cin>>P[i];
    P[i]--;
  }
  for(int i=0;i<N;i++){
    cin>>C[i];
  }
  int64_t ans=-1e18-10;
  for(int s=0;s<N;s++){
    vector<int>q;
    vector<int>num(N,-1);
    int d=P[s];
    int64_t roopsum=0;
    while(num[d]==-1){
      num[d]=q.size();
      q.push_back(d);
      roopsum+=C[d];
      d=P[d];
    }
    int Q=q.size();
    int roop=Q-num[d];
    if(Q>K){
      int64_t cost=0;
      for(int i=0;i<K;i++){
        cost+=C[q[i]];
        chmax(ans,cost);
      }
    }
    else if(roopsum<=0){
      int64_t cost=0;
      for(int i=0;i<Q;i++){
        cost+=C[q[i]];
        chmax(ans,cost);
      }
    }
    else{
      int64_t cost=0;
      for(int i=0;i<Q;i++){
        cost+=C[q[i]];
        chmax(ans,cost+(K-(i+1))/roop*roopsum);
      }
    }
  }
  cout<<ans<<endl;
  return 0;  
}