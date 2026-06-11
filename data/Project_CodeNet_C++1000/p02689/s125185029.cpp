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
	int n, m, x, y;
	cin >> n >> m;
	vector<int> v(n + 1);
	vector<bool> remove(n + 1, false);
	for (int i = 1; i <= n; i++) cin >> v[i];
	while (m--) {
		cin >> x >> y;
		if (v[x] >= v[y]) {
			remove[y] = true;
		}
		if (v[x] <= v[y]) {
			remove[x] = true;
		}
	}
	int count = n;
	for (int i = 1; i <= n; i++) {
		if (remove[i]) {
			count--;
		}
	}
	cout << count;
}