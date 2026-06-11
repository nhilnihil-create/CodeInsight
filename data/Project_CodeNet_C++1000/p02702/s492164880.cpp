#include <bits/stdc++.h>
#define vsort(v) sort(v.begin(), v.end())
#define rvsort(v) sort(v.begin(), v.end(), greater<ll>())
#define prvsort(v) sort(v.begin(), v.end(), greater<pair<ll, ll>>())
#define ll long long
#define ld long double
#define fixset(val) fixed << setprecision(10) << val 
#define rep(i, s, g) for (ll i = (s); i < (g); i++)
#define mod 1000000007
#define vfind(v, target) find(v.begin(), v.end(), target)
#define notFound(v, target) (vfind(v, target) == v.end())

using namespace std;

int main()
{
  string S; cin >> S;
  ll N = S.size(), a, b = 1, ans = 0;
  vector<ll> amari(N + 1), count(2020, 0);
  amari[N] = 0;
  count[0] = 1;
  for (ll i = N - 1; i >= 0; i--) {
  	a = S[i] - '0';
    amari[i] = (amari[i + 1] + (a * b) % 2019) % 2019;
    count[amari[i]]++;
    b = (b * 10) % 2019;
  }
  rep(i, 0, 2020) {
  	ans += count[i] * (count[i] - 1) / 2;
  }
  cout << ans << endl;
}