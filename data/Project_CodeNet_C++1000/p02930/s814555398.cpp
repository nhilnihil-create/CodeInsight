#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <map>
#include <numeric>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <bitset>
#include <complex>
#include <stack>
#include <cstdint>



#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rrep(i, n) for(ll i = (ll)(n-1); i >= 0; i--)
#define repi(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rrepi(i,a,b) for(ll i=(ll)(b);i>=(ll)(a);i--)

#define all(x) (x).begin(),(x).end()

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;cin>>n;
  vector<vector<ll>>ed(n,vector<ll>(n,-1));
  function<void(ll,ll,ll)>dfs=[&](ll l,ll r,ll id){
    if(r-l==1)return;

    repi(i,l,r)repi(j,l,r){
      ed[i][j]=id;
    }
    ll m=(l+r)/2;
    dfs(l,m,id+1);
    dfs(m,r,id+1);
  };
  dfs(0,n,1);
  rep(i,n){
    repi(j,i+1,n){
      cout<<ed[i][j]<<" ";
    }
    cout<<endl;
  }

  return 0;

}
