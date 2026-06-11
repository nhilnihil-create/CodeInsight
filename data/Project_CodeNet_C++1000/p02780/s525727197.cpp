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
  ll N, K; cin >> N >> K;
  vector<ll> A(N);
  rep(i, 0, N) cin >> A[i];
  ld kitai = 0;
  rep(i, 0, K) {
  	kitai += (A[i] + 1) / 2.0;
  }
  ld ans = kitai;
  rep(i, 0, N - K) {
    kitai += (A[i + K] - A[i]) / 2.0;
    if (ans < kitai) ans = kitai;
  }
  cout << fixset(ans) << endl;
}