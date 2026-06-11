#include<bits/stdc++.h>
#define Imposter ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define ll long long int
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3")
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>//s.order_of_key(val) *s.find_by_order(ind)
using namespace std;
#define f(n) for(ll i=0;i<n;i++)
#define rep(i,a,b) for(i=a;i<b;i++)
#define input(arr,n) for(ll i1=0;i1<n;i1++ )cin>>arr[i1]
#define vll vector<ll>
#define vlll vector<vll>
#define all(x) x.begin(),x.end()
ll MOD=1e9 +7;
ll power(ll x, ll y, ll p) {
    ll res = 1;    x = x % p;
    while(y > 0) {
        if(y & 1) res = (res*x) % p;
        y = y>>1;    x = (x*x) % p;
    } return res;
}
ll mpower(ll x, ll y, ll m){
  if(y < 0){
    return 0;
  }else if(y == 0){
    return 1LL;
  }else if(y%2 == 0){
    return mpower(x,y/2,m)*mpower(x,y/2,m)%m;
  }else{
    return mpower(x,y-1,m)*x%m;
  }
}


int main()
{
    Imposter

    ll n; cin >> n; 
  vector<ll> a(n); f(n){ cin >> a[i]; }
  
  //main
  vector<ll> zero(61), one(61);
  f(n){
    for(int j=0;j<61;j++){
      if((a[i]>>j)%2==1){
        one[j]++;
      }else{
        zero[j]++;
      }
    }
  }
  ll ans = 0;
  f(61){
    if(zero[i] != 0 && one[i] != 0){
      ll tmp = ((mpower(2,i,MOD)*zero[i]%MOD)*one[i])%MOD;
      ans = (ans+tmp)%MOD;
      if(ans < 0){
        ans += MOD; 
      }
    }
  }
  cout << ans << endl;
  return 0;
}