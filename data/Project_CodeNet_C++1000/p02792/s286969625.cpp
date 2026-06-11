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
  ll N, a = 1, ans = 0; cin >> N;
  vector<vector<ll>> mtrx(10, vector<ll>(10, 0));
  rep(k, 1, N + 1) {
    if (k / a == 10) a *= 10;
  	mtrx[k / a][k % 10]++;
  }
  rep(i, 0, 10) {
  	rep(j, 0, 10) {
      	ans += mtrx[i][j] * mtrx[j][i];
    }
  }
  cout << ans << endl;
}