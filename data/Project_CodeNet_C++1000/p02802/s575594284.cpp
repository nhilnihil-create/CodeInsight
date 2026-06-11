#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <cmath>
#include <algorithm>
#include <vector>
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
  int N,M;
  cin>>N>>M;
  vector<int>p(M);
  vector<string>S(M);
  for(int i=0;i<M;i++){
    cin>>p[i]>>S[i];
  }
  vector<bool>ok(N+1,false);
  int sumw=0,suma=0;
  vector<int>WA(N);
  for(int i=0;i<M;i++){
   if(ok[p[i]]){continue;}
   if(S[i]=="AC"){ok[p[i]]=true;suma++;sumw+=WA[p[i]];}
   if(S[i]=="WA"){WA[p[i]]++;}
  }
  cout<<suma<<" "<<sumw<<endl;
  return 0;
}