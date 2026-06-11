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
  int64_t N;
  cin>>N;
  vector<int>a(N+1);
  for(int i=1;i<=N;i++){
    cin>>a[i];
  }

  vector<int>ans(N+1);
  int tot=0;
  for(int64_t i=N;i>=1;i--){
    int cnt=0;
    for(int64_t j=2;j<=N/i;j++){
      if(i*j<=N){cnt+=ans[i*j];}
    }
    if(cnt%2!=a[i]){ans[i]++;tot++;}
  }

  cout<<tot<<endl;
  if(tot==0){return 0;}
  for(int i=1;i<=N;i++){
    if(ans[i]>0){cout<<i;
    if(i<N){cout<<" ";}
    }
    //if(i<=N-1){cout<<" ";}
  }cout<<endl;
  return 0;
}