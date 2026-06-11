#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll a, b, c, d;
vector<ll> ans;

int main() {
	cin >> a >> b >> c >> d;
	ans.emplace_back(a * c);
	ans.emplace_back(a * d);
	ans.emplace_back(b * c);
	ans.emplace_back(b * d);
	if (a * b <= 0 || c * d <= 0)
		ans.emplace_back(0);
	sort(ans.rbegin(), ans.rend());
	cout << ans[0] << endl;
}
