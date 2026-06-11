#include <bits/stdc++.h>
#include <unordered_set>
#include <random>
using namespace std;
#define ll long long
#define fr first
#define sc second
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll N, A, B; cin >> N >> A >> B;

	ll ans = N / (A + B) * A;
	ans += min(N - N / (A + B) * (A + B), A);
	cout << ans << '\n';
	return 0;
}