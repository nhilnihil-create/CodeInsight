#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (ll i = 0; i < (n); i++)
typedef pair<ll,ll> P;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}


int main(){

  ll n;
  cin >> n;
  string s;
  cin >> s;
  ll ans = 0;
  ll r = n-1;
  ll l = 0;
  while(r > l){
    if (s[l] == 'R'){
      l++;
    }
    if (s[r] == 'W'){
      r--;
    }

    if (s[l] == 'W' && s[r] == 'R'){
      ans++;
      l++; r--;
    }

  }

  cout << ans << endl;

  return 0;
}