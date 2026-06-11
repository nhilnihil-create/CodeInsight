#include <bits/stdc++.h>

/*                    ॐ Shree ॐ                     */
/* ॐ ॐ ॐ
ॐ भूर् भुवः स्वः
तत् सवितुर्वरेण्यं
भर्गो देवस्य धीमहि
धियो यो नः प्रचोदयात्
*/
using namespace std;
typedef long long int ll;
vector<int> ve(3006, 0);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
// online submission
#endif
	long long int a, b, c;
	cin >> a >> b >> c;
	ll mx = 0, ans = 0;
	ll x = min(b - 1, c);
	ll t = floor((double)(a * x / b)) - a * floor((double)(x / b));
	cout << t;

}