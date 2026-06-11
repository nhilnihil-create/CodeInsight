#include <bits/stdc++.h>
typedef long long ll;
#define ALL(l)  (l).begin(),(l).end()
#define rep(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
using namespace std;

//const ll mod =  1000000007;
//const ll maxn = 1000000000;

//---------------------------------------------------------------------------------------------------
using vi = vector<int>; // intの1次元の型に vi という別名をつける
using vll = vector<ll>; // intの1次元の型に vi という別名をつける
using vvll = vector<vll>; // intの2次元の型に vvi という別名をつける
using vs = vector<string>; // stringの1次元の型に vs という別名をつける
using pll = pair<ll, ll>; // これ以降 pii という型名はpair<ll, ll> と同じ意味で使える
//---------------------------------------------------------------------------------------------------
//vector<bool> seen;
vll ans(200001,0);
 vll g[200001];
 vector<bool> seen;
void dfs(ll p,ll x) {
   seen[p] = true;
    if(p!=0)ans.at(p)+=x;
    
    for (auto next_v : g[p]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(next_v,ans.at(p)); // 再帰的に探索
    }
}

int main() {
  ll n,q;
  cin>>n>>q;
  
 
  vll a(n-1),b(n-1);
  rep(i,n-1){
      cin>>a.at(i)>>b.at(i);
      g[a.at(i)-1].push_back(b.at(i)-1);
       g[b.at(i)-1].push_back(a.at(i)-1);
  }
  
  vll p(q),x(q);
  rep(i,q){
      cin>>p.at(i)>>x.at(i);
      p.at(i)--;
      ans.at(p.at(i))+=x.at(i);
  }
  seen.assign(n, false); 
  dfs(0,ans.at(0));
  rep(i,n-1){
      cout<<ans.at(i)<<" ";
  }
  cout<<ans.at(n-1)<<endl;
}

