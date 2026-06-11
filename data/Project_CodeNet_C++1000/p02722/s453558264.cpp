#include<bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define rrep(i, n) for (int (i) = 1; (i) <= (n); (i++))
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define pb push_back
#define eb emplace_back
#define yn {puts("Yes");}else {puts("No");}
#define printd(x) printf("%.12f\n", x);
template<class T> bool chmin(T& a, const T& b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> bool chmax(T& a, const T& b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector< ll > divisor(ll n) {
  vector< ll > ret;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}

int main() {
	ll n;
	cin >> n;

	vector<ll> divmin1 = divisor(n - 1);
	vector<ll> div = divisor(n);

	ll ans = 0;
	ans += divmin1.size() - 1;

	rep (i, div.size()) {
		if (div[i] == 1) continue;
		ll tmp = n;
		while (tmp % div[i] == 0) tmp /= div[i];
		if (tmp % div[i] == 1) ans++;
	}

	cout << ans << endl;
	return 0;
}