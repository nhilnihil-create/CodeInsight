#include<iostream>
#include<algorithm>
#include <string>
#include <cstring>
#include<climits>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;
typedef long long ll;
pair<ll, ll > a[200001];

int main() {
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
	
	int n;
	ll D, A;
	cin >> n >> D >> A;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second; 
	}

	sort(a, a + n);

	queue<pair<ll, ll>> s;
	ll cnt = 0;
	ll ans = 0;

	for (int i = 0; i < n; i++) {
		while (!s.empty() && s.front().first < a[i].first) {
			cnt -= s.front().second;
			s.pop();
		}
		a[i].second -= cnt * A;
		if (a[i].second <= 0)continue;
		else {
			ll t = a[i].second / A;
			if (a[i].second % A != 0)t += (ll)1;
			ans += t;
			cnt += t;
			s.push({ a[i].first + D + D, t });
		}
	}

	cout << ans << '\n';





}