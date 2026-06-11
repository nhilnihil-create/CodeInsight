#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (int)(n);i++)
using ll = long long;
const ll MOD=1000000007;
//const ll MOD=998244353;
const long long INF = 1LL << 60;
const double pi=acos(-1.0);

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int main()
{
  ll N; cin>>N;
  vector<ll> A(N); rep(i,N) cin>>A[i];
  
  //まずは合計
  ll sum=0; rep(i,N) sum+=A[i]; sum/=2;
  
  
  //x0求める
  ll ssum=0; for(int i=0;i<N;i+=2) ssum+=A[i];
  ll x0=ssum-sum;
  
  //x求める
  vector<ll> x(N); x[0]=x0;
  for(int i=1;i<N;i++) x[i]=A[i-1]-x[i-1];
  
  rep(i,N){
    if(i!=0) cout<<" ";
    cout<<x[i]*2;
  }
  cout<<endl;
  
  return 0;
}