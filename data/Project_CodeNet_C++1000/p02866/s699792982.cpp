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

ll mypow(ll a, ll b) {
  ll two;
  ll tmp;
  ll ans = 1;
  while(b>0) {
    two = 1;
    tmp = a;
    while(2*two<b) {
      two *= 2;
      tmp *= tmp;
      tmp %= mod1;
    }
    b -= two;
    ans *= tmp;
    ans %= mod1;
  }
  return ans;
}

int main() {
  int N;
  cin>>N;
  int D[N];
  map<int, ll> amap;
  for(int i=0;i<N;++i) {
    cin>>D[i];
    amap[D[i]]++;
  }
  bool ok = true;
  int maxnum;
  bool tmp = false;
  for(int i=0;i<=N;++i) {
    if(amap[i]==0) {
      if(!tmp) maxnum = i-1;
      tmp = true;
    }
    else {
      if(tmp) ok = false;
    }
  }
  if(D[0]!=0 || amap[0]>1 || !ok) {
    cout<<0<<endl;
    return 0;
  }
  ll ans = 1;
  for(int i=1;i<=maxnum;++i) {
    ans *= mypow(amap[i-1], amap[i]);
    ans %= mod1;
  }
  cout<<ans<<endl;
}

