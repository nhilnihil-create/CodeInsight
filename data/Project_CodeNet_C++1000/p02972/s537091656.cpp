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
  vector<ll> a(N+1); rep(i,N) cin>>a[i+1];
  
  vector<int> vec(N+1,-1);
  for(int i=N;i>=1;i--){
    ll count=0;
    for(int j=2*i;j<=N;j+=i) if(vec[j]) count++;
    count%=2;
    if(count==a[i]) vec[i]=0;
    else vec[i]=1;
  }
  
  ll M=0; rep(i,N) if(vec[i+1]) M++; cout<<M<<endl;
  
  vector<ll> ans_list(0); rep(i,N) if(vec[i+1]) ans_list.push_back(i+1);  
  ll sz=ans_list.size();
  rep(i,sz){
    if(i!=0) cout<<" ";
    cout<<ans_list[i];
  }
  cout<<endl;
  
  return 0;
}