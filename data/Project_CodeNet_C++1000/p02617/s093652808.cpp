#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

const double EPS = 1e-10;

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;

int main(){
  ll n; cin >> n;
  ll ans = 0;
  repr(i,1,n+1){
    ans += (ll)i*(n-i+1);
  }
  rep(i,n-1){
    int u,v; cin >> u >> v;
    if(u > v) swap(u,v);
    ans -= (ll)u*(n-v+1);
  }
  cout << ans << endl;
}
