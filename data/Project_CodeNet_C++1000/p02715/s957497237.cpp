#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <iomanip>
#include <climits>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector< vector<int> > VVI;
typedef vector< vector<ll> > VVL;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define pf push_front
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ub upper_bound
#define lb lower_bound

ll modpow(ll a,ll n,ll mod){
  ll res=1;
  while(n){
    if(n&1) res=res*a%mod;
    a=a*a%mod;
    n>>=1;
  }
  return res;
}

int main(){
  ll N,K;
  cin>>N>>K;
  VL X(K+1);
  ll mod=1e9+7;
  rep(i,K) X[i+1]=modpow(K/(i+1),N,mod);
  rep(i,K) rep(j,K/(K-i)-1) (X[K-i]+=mod-X[(K-i)*(j+2)])%=mod;
  ll ans=0;
  rep(i,K) (ans+=X[i+1]*(i+1)%mod)%=mod;
  cout<<ans<<endl;
}