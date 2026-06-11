#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define pqueue priority_queue
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

ll frac[5000];

ll comb(ll a, ll b) {
  ll ans = frac[a];
  ll sh1, sh2;
  ll h = mod-2;
  ll two;
  while(h>0) {
    two = 1;
    sh1 = frac[b];
    sh2 = frac[a-b];
    while(2*two<h) {
      two *= 2;
      sh1 *= sh1;
      sh1 %= mod;
      sh2 *= sh2;
      sh2 %= mod;
    }
    h -= two;
    ans *= sh1*sh2%mod;
    ans %= mod;
  }
  return ans;
}

int main() {
  frac[0] = 1;
  for(ll i=1;i<5000;++i) frac[i] = frac[i-1]*i%mod;
  ll S;
  cin>>S;
  ll ans = 0;
  for(ll i=1;i<=S/3;++i) {
    ans += comb(S-3*i+i-1, i-1);
    ans %= mod;
  }
  cout<<ans<<endl;
}

