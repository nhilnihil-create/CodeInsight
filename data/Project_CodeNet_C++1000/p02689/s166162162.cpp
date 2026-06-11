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

int main() {
  int N,M;
  cin>>N>>M;
  vector<int>H(N);
  for(int i=0;i<N;i++){
    cin>>H[i];
  }
  vector<int>A(M),B(M);
  for(int i=0;i<M;i++){
    cin>>A[i]>>B[i];
    A[i]--;B[i]--;
  }
  //vector<int>MAX(N+1);
  vector<bool>high(N+1,true);
  for(int i=0;i<M;i++){
     if(H[A[i]]>H[B[i]]){high[B[i]+1]=false;}
     else if(H[A[i]]<H[B[i]]){high[A[i]+1]=false;}
     else{high[A[i]+1]=false;high[B[i]+1]=false;}
     //cout<<H[A[i]]<<" "<<H[B[i]]<<endl;
  }
  int cnt=0;
  for(int i=1;i<N+1;i++){
    if(high[i]){cnt++;}
  }
  cout<<cnt<<endl;
  return 0;
}