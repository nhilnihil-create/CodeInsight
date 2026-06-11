#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

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

const int INF=1001001001;

int main() {
  int N,K,S;
  cin>>N>>K>>S;
  vector<int>A(N);
  int k=K;
  for(int i=0;i<N;i++){
    if(k>0){A[i]=S;k--;}
    else if(S==1000000000){A[i]=1;}
    else{A[i]=S+1;}
  }
  for(int i=0;i<N;i++){
    cout<<A[i];
    if(i<N-1){cout<<" ";}
  }cout<<endl;
  return 0;
}