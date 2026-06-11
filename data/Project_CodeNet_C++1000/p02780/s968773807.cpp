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
int main() {
  int N,K;
  cin>>N>>K;
  vector<int>p(N);
  for(int i=0;i<N;i++){
    cin>>p[i];
  }
  vector<double>E(N+1);
  double tot=0;
  for(int i=0;i<N;i++){
    double sum=0;
    for(int j=1;j<=p[i];j++){
      sum+=j;
    }
    tot+=sum/p[i];
    E[i+1]=tot;
  }
  double ans=0;
  for(int i=1;i<=N-K+1;i++){
     chmax(ans,E[i+K-1]-E[i-1]);
  }
  cout<<fixed<<setprecision(10)<<ans<<endl;
  return 0;
}