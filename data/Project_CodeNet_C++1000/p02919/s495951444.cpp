#include <set>
#include<algorithm>
#include<iostream>
#define ll long long
using namespace std;

const int maxn = 1e5;

int pos[maxn + 11];

int main() {
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		pos[x] = i;
	}
	set <int> s;
	set <int> ::iterator itl, itr;
	s.insert(0); s.insert(n + 1);s.insert(n + 2);s.insert(-1);
	ll ans = 0;
	for (int i = n; i >= 1; i--) {
		itl = s.lower_bound(pos[i]); itr = itl--;
		int l = *itl;
		int r = *itr;
		if (l == 0) {
			itr++;
			int R = *itr;
			if (r != n + 1) {
				ans += 1ll * pos[i] * (R - r) * i;
			}
		}
		else if (r == n + 1) {
			itl--;
			int L = *itl;
			ans += 1ll * (l - L) * (n - pos[i] + 1) * i;
		}
		else {
			itl--; itr++;
			int L = *itl; int R = *itr;
			ans += (1ll * (l - L) * (r - pos[i]) + 1ll * (R - r) * (pos[i] - l)) * i;
		}
		s.insert(pos[i]);
	}
	cout << ans << endl;
}