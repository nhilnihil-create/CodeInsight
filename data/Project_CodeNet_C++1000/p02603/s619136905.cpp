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

	int n; cin >> n;
	ll money = 1000;

	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	for (int i = 1; i < n; i++) {
		if (v[i - 1] < v[i]) {
			ll stock = money / v[i - 1];
			money -= money / v[i - 1] * v[i - 1];
			money += stock * v[i];
		}
	}
	cout << money << '\n';
	return 0;
}