#include <set>
#include<algorithm>
#include<iostream>
#include<functional>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
const int maxn = 1e5;

pii val[maxn + 11];
int pos[maxn + 11];

int main() {
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> val[i].first;
		val[i].second = i;
	}sort(val + 1, val + 1 + n);
	for (int i = 1;i <= n;i++)
		pos[i] = val[i].second;
	set <int> s;
	set <int> ::iterator itl, itr;
	s.insert(0); s.insert(n + 1);s.insert(n + 2);s.insert(-1);
	ll ans = 0;
	for (int i = n; i >=1; i--) {
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