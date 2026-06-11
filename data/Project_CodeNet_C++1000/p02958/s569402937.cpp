#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <cmath>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
vector<pair<int64_t,int64_t>>func(int64_t x){
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

int main(){
  int N;
  cin>>N;
  vector<int>P(N);
  for(int i=0;i<N;i++){
    cin>>P[i];
  }
  int cnt=0;
  for(int i=0;i<N;i++){
    if(P[i]!=i+1){cnt++;}
  }
  if(cnt==2||cnt==0){cout<<"YES"<<endl;}
  else{cout<<"NO"<<endl;}
  return 0;
}