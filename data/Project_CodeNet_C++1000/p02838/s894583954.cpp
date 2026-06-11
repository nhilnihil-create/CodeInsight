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

int main() {
  int N;
  cin>>N;
  ll A[N];
  for(int i=0;i<N;++i) cin>>A[i];
  ll two[64], two1[64];
  for(ll i=0;i<64;++i) {
    two[i] = 0;
    two1[i] = 0;
    for(int j=0;j<N;++j) {
      if((A[j]&(1ull<<i))==0) two[i] += (1ull<<i);
      two[i] %= mod;
      two1[i] += (1ull<<i)&A[j];
      two1[i] %= mod;
    }
  }
  ll ans = 0;
  for(int i=0;i<N;++i) {
    for(ll j=0;j<64;++j) {
      if((A[i]&(1ull<<j))!=0) ans += two[j];
      else ans += two1[j];
      ans %= mod;
    }
  }
  ll h=mod-2;
  ll twotwo;
  ll tmp;
  while(h>0) {
    twotwo = 1;
    tmp = 2;
    while(2*twotwo<h) {
      twotwo *= 2;
      tmp *= tmp;
      tmp %= mod;
    }
    h -= twotwo;
    ans *= tmp;
    ans %= mod;
  }
  cout<<ans<<endl;
}

