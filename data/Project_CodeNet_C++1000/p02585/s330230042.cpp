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
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  ll N, K;
  cin>>N>>K;
  ll P[N], C[N];
  for(int i=0;i<N;++i) {
    cin>>P[i];
    P[i]--;
  }
  for(int i=0;i<N;++i) cin>>C[i];
  ll ans=-big;
  ll cycle[N], now;
  ll tmpans;
  ll get1[N];
  for(int i=0;i<N;++i) {
    now = i;
    get1[i] = 0;
    cycle[i] = -1;
    for(ll j=0;j<K;++j) {
      now = P[now];
      get1[i] += C[now];
      ans = max(ans, get1[i]);
      if(now==i) {
        cycle[i] = j+1;
        break;
      }
    }
  }
  ll num;
  for(int i=0;i<N;++i) {
    if(cycle[i]==-1 || get1[i]<=0) continue;
    get1[i] = (K/cycle[i]-1)*get1[i];
    now = i;
    num = K/cycle[i]-1;
    for(int j=0;j<K-num*cycle[i];++j) {
      now = P[now];
      get1[i] += C[now];
      ans = max(ans, get1[i]);
    }
  }
  cout<<ans<<endl;
}

