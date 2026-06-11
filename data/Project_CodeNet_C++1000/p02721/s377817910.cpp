
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> ii;

#define repa(i, a, b) for (auto i = (a); i <= (b); i++)
#define repd(i, a, b) for (auto i = (a); i >= (b); i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define zero(a)  memset((a), 0, sizeof (a))
#define sz(x) (int)(x).size()
#define debug(x) cout << (x) << "\n";
#define mp make_pair
#define pb push_back

int n, k, c;
string s;

void solve() {
	s = " " + s;
	int L[n + 2], R[n + 2];
	zero(L); zero(R);
	auto w{1}, i{1};
	while (i <= n) {
		if (w > k) break;
		if (s[i] == 'o') {
			L[w] = i;
			++w;
			i += c + 1;
		} else ++i;
	}
	w = k;
	i = n;
	while (i >= 1) {
		if (w < 1) break;
		if (s[i] == 'o') {
			R[w] = i;
			--w;
			i -= c + 1;
		} else --i;
	}
	repa(j, 1, k) {
		if (L[j] == R[j]) { 
			cout << L[j] << "\n";
		}
	}
	cout << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k >> c;
	cin >> s;
	solve();
	return 0;
}
