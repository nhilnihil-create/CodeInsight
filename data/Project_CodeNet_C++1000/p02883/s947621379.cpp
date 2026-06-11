#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;


const ll INF = 1e18;

int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  vector<ll> f(n);
  rep(i,n)cin>>a[i];
  rep(i,n)cin>>f[i];
  sort(a.begin(),a.end());
  sort(f.rbegin(),f.rend());

  ll l=0;
  ll r=1000000000001;
  while(l+1<r){
    ll c=(l+r)/2;
    ll cost=0;
    rep(i,n){
      ll temp=(c-1)/f[i];
      ll x=a[i]-temp;
      if (x>0)cost+=x;
    }
//    cout<<cost<<" "<<c<<endl;
    if (cost<=k)r=c;
    else l=c;
  }
cout<<l;
}
