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
	int A, B, C, K;
	cin >> A >> B >> C >> K;

	int cnt = 0;
	while (A >= B) B *= 2, cnt++;
	while (B >= C) C *= 2, cnt++;
	if (cnt > K) cout << "No\n";
	else cout << "Yes\n";
	return 0;
}