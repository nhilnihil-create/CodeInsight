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
  ll N;
  cin>>N;
  vector<ll> prime;
  map<ll, ll> amap;
  for(ll i=2;i*i<=N;++i) {
    if(N%i==0) {
      prime.push_back(i);
      while(N%i==0) {
        amap[i]++;
        N /= i;
      }
    }
  }
  if(N>1) {
    prime.push_back(N);
    amap[N]++;
  }
  int ans = 0;
  for(int i=0;i<prime.size();++i) {
    for(int j=0;j<1000;++j) {
      if(amap[prime[i]]<j*(j+1)/2) {
        ans += j-1;
        break;
      }
    }
  }
  cout<<ans<<endl;
}

