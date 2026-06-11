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

ll bit[2005];

void add(ll x) {
  while(x<2005) {
    bit[x]++;
    x += x&-x;
  }
}

ll sum(ll x) {
  ll ans = 0;
  while(x>0) {
    ans += bit[x];
    x -= x&-x;
  }
  return ans;
}

int main() {
  ll N, K;
  cin>>N>>K;
  ll A[N];
  vector<ll> arr;
  map<ll, ll> amap;
  for(ll i=0;i<N;++i) {
    cin>>A[i];
    if(amap[A[i]]==0) arr.push_back(A[i]);
    amap[A[i]]++;
  }
  ll ans = 0;
  for(ll i=0;i<N;++i) {
    ans += i-sum(A[i]);
    ans %= mod;
    add(A[i]);
  }
  ans *= K;
  ans %= mod;
  sort(arr.begin(), arr.end());
  ll tmp = N-amap[arr[0]];
  for(ll i=0;i<arr.size()-1;++i) {
    ans += (K-1)*K/2%mod*tmp%mod*amap[arr[i]]%mod;
    ans %= mod;
    tmp -= amap[arr[i+1]];
  }
  cout<<ans<<endl;
}

