#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
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
	int N; cin >> N;
	vector<pll> v(N);
	for (int i = 0; i < N; i++) cin >> v[i].fr >> v[i].sc;

	set<ll> st1, st2;
	for (int i = 0; i < N; i++) st1.insert(v[i].fr + v[i].sc);
	for (int i = 0; i < N; i++) st2.insert(v[i].fr - v[i].sc);

	ll ans = 0;
	ans = max(ans, *(st1.rbegin()) - *(st1.begin()));
	ans = max(ans, *(st2.rbegin()) - *(st2.begin()));
	cout << ans << '\n';

	return 0;
}