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
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  ll N;
  cin>>N;
  vector<ll> prime;
  for(ll i=1;i*i<=N;++i) {
    if(N%i==0) {
      prime.push_back(i);
      if(i!=N/i) prime.push_back(N/i);
    }
  }
  ll tmp = N-1;
  vector<ll> prime1;
  for(ll i=1;i*i<=tmp;++i) {
    if(tmp%i==0) {
      prime1.push_back(i);
      if(i!=tmp/i) prime1.push_back(tmp/i);
    }
  }
  int ans = prime1.size() - 1;
  for(int i=0;i<prime.size();++i) {
    if(prime[i]==1) continue;
    tmp = N;
    while(tmp%prime[i]==0) tmp /= prime[i];
    if(tmp%prime[i]==1) ans++;
  }
  cout<<ans<<endl;
}

