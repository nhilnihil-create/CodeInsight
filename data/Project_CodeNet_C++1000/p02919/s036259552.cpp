#include <iostream>
#include <algorithm>
#include <set>
#include <utility>
using namespace std;

int r[100009];
set<int> st;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		r[a] = i;
	}
	st.insert(0); st.insert(n + 1);
	long long ans = 0;
	for (int i = n; i >= 1; i--) {
		auto ri = st.lower_bound(r[i]);
		auto li = ri; li--;
		long long p = 0;
		if (ri != --st.end()) {
			int t = 0;
			t -= (*ri); ri++;
			t += (*ri); ri--;
			p += 1LL * (r[i] - (*li)) * t;
		}
		if (li != st.begin()) {
			int t = 0;
			t += (*li); li--;
			t -= (*li); li++;
			p += 1LL * ((*ri) - r[i]) * t;
		}
		ans += 1LL * p * i;
		st.insert(r[i]);
	}
	cout << ans << '\n';
	return 0;
}	