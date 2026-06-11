#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<int,int>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;
const int INF=1e9;


int main(){
  int n,k;
  cin>>n>>k;
  vector<int> h(n);
  rep(i,n)   cin>>h[i];

  if(n<=k){//すべて必殺技
    cout<<0<<endl;
    return 0;
  }

  int m=n-k;//攻撃する敵数
  
  sort(h.begin(),h.end());
  ll ans=0;

  rep(i,m){
    ans+=h[i];
  }

  cout<<ans<<endl;
}
