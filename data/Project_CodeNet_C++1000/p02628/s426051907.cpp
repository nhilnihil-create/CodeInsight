#include<bits/stdc++.h>
#include <math.h>
#include <map>
#include <unordered_map>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define lper(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define pb(s) push_back(s)
#define CST(x) cout<<fixed<<setprecision(x)
#define ci(x) cin >>x
#define co(x) cout<<x<<endl
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
using vvpl=vector<vector<pl>>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9;
const ll INF=4e18;
const ll dy[4]={1,0,-1,0};
const ll dx[4]={0,-1,0,1};
long long fac(ll a) {
 long long ans=1;
 while(a>1){
 ans*=a;
 ans%=1000000007;
     a--;
    }
    return ans;
     }

ll PS(ll x) {
  ll c=1;
  rep(i,x) {
    c=c*2;
  }
  return c;
}


int main() {
ll N;
  cin >>N;
  ll K;
  cin >>K;
  
  vl p(N);
  
  rep(i,N) {
cin >>p.at(i);
  }

  sort(all(p));
  ll sum=0;
  
  rep(i,K) {
sum+=p.at(i);
  }
  
  
  cout<<sum<<endl;
}


  