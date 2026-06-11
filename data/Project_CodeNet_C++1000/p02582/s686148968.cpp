#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define faster ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define read freopen("in.txt", "r", stdin)
#define write freopen("out.txt", "w", stdout)
#define mem(x, n) memset(x, n, sizeof(x))
#define all(x) x.begin(), x.end()
#define endl "\n"

int main() {
	faster;

	string s;
	cin >> s;
	int cnt = 0, curr = 0;
	for (int i = 0; i < 3; i++) {
		if (s[i] == 'R') {
			curr++;
		} else {
			curr = 0;
		}
		cnt = max(cnt, curr);
	}

	cout << cnt << endl;

	return 0;
}