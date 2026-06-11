#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

#define ll long long
 
ll f(ll n) 
{
  return n * (n - 1) / 2;
}
 
int main() 
{
  ll N;
  cin >> N;
  vector<ll> a(N);
  map<ll, ll> mp;
  for (ll i = 0; i < N; i++) 
  {
    cin >> a[i];
    mp[a.at(i)]++;
  }
  ll ans = 0;
  for (auto const& b : mp) ans += f(b.second);
  for (auto a : a) cout << ans - f(mp[a]) + f(mp[a] - 1) << "\n";
}