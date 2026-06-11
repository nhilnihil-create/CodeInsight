#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int INF = 1e9 + 10;
const ll MOD = 1e9 + 7;

void printv(vector<ll> v) {
  for (ll i : v)
    cout << i << " ";
  cout << endl;
}

bool operator<(pair<bool, ll> p1, pair<bool, ll> p2) {
  return (p1.second == p2.second ? p1.first < p2.first : p1.second < p2.second);
}

int main() {
  ll n;
  cin >> n;
  ll ans = 0;
  for (ll i = 1; i <= n; i++) {
    ans += i*(i+1)/2;
  }
  for (ll i = 0; i < n-1; i++){
    ll u, v;
    cin >> u>>v;
    if (u<v){
      ans -= u*(n-v+1);
    }else{
      ans -= v*(n-u+1);
    }
  }
  cout << ans <<endl;
}
