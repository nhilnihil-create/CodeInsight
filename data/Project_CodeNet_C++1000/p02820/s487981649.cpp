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
int N,K,R,S,P;
string T;
int func(int i){
  if(T[i]=='r'){return P;}
  if(T[i]=='s'){return R;}
  if(T[i]=='p'){return S;}
}
int main() {
  cin>>N>>K>>R>>S>>P>>T;
  int64_t cnt=0;
  for(int k=0;k<K;k++){
    bool use=false;
    for(int i=k;i<N;i+=K){
      if(i>=K&&T[i-K]==T[i]&&use){use=false;}
      else{cnt+=func(i);use=true;}//cout<<cnt<<endl;
    }
  }
  cout<<cnt<<endl;
  return 0;
}