#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (ll i = 0; i < (n); i++)
typedef pair<ll,ll> P;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}


int main(){

  ll n, d;
  cin >> n >> d;
  ll ans = 0;
  rep(i,n){
    ll x,y;
    cin >> x >> y;
    if(x*x+y*y <= d*d){

      ans ++;
    }
  }
  cout << ans << endl;

  return 0;
}