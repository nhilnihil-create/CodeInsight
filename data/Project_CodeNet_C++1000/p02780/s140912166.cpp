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

double pro(double x){
  double tot=0;
  for(int i=1;i<=x;i++){
    tot+=i;
  }
  return tot/x;
}
int main(){
  double N,K;
  cin>>N>>K;
  vector<double>p(N+1);
  for(int i=1;i<=N;i++){
    cin>>p[i];
  }
  vector<double>s(N+1);
  double sum=0;
  for(int i=1;i<=N;i++){
    sum+=pro(p[i]);
    s[i]=sum;
  }
  double ans=0;
  for(int i=1;i<=N-K+1;i++){
    double t=s[i+K-1]-s[i-1];
    ans=max(ans,t);
  }
  cout<<fixed<<setprecision(10)<<ans<<endl;
  return 0;
}