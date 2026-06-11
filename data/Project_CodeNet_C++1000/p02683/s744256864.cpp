#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
vector<pair<int64_t,int64_t>>prime_factorize(int64_t x){
  vector<pair<int64_t,int64_t>>p;
  for(int64_t i=2;i*i<=x;i++){
    int cnt=0;
    if(x%i==0){
    while(x%i==0){cnt++;x/=i;}
    p.push_back(make_pair(i,cnt));
    }
  }
  if(x!=1){p.push_back(make_pair(x,1));}
  return p; 
}
const int MOD=1000000007;
int main() {
  int N,M,X;
  cin>>N>>M>>X;
  vector<int>C(N);
  vector<vector<int>>A(N,vector<int>(M));
  for(int i=0;i<N;i++){
    cin>>C[i];
    for(int j=0;j<M;j++){
      cin>>A[i][j];
    }
  }
  int MIN=INF;
  for(auto s=0;s<(1<<N);s++){
    int cost=0;
    vector<int>sum(M);
    for(int i=0;i<N;i++){
      if((s>>i)&1){
        cost+=C[i];
        for(int j=0;j<M;j++){
          sum[j]+=A[i][j];
        }
      }
    }
    bool ok=true;
    for(int j=0;j<M;j++){
      if(sum[j]<X){ok=false;}
    }
    if(ok){chmin(MIN,cost);}
  }
  if(MIN==INF){cout<<-1<<endl;}
  else{cout<<MIN<<endl;}
  return 0;
}