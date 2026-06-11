//sppsfver - 20.08.2020
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair <ll, ll>;
const int MAX = 1e5+5;

ll n, k, x, y, ans;

ll calDis (ll a, ll b){
	return (a*a + b*b);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	while (n--){
		cin >> x >> y;
		ans += calDis(x, y) <= k*k;
	}
	cout << ans << endl;
	return 0;
}
