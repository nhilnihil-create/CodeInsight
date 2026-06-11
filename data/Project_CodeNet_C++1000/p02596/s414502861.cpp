#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using pii = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back

ll modpow(ll m,ll n,ll p) {
  if(n==0) return 1;
  ll res=modpow(m,n/2,p);
  if(n%2==0) res=(res*res)%p;
  else res=(((res*res)%p)*m)%p;
  return res;
}

int main() {
  ll ans=-1;
  ll k; cin>>k;

  for(ll n=1;n<=k;n++) {
    if(7*(modpow(10,n,9*k)-1)%(9*k)==0) {
      ans=n;
      break;
    }
  }
  cout<<ans<<endl;
}
