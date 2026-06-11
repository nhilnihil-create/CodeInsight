#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define PP pop_back
#define sz(x) (int)(x.size())

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

	int n, m, a;
	cin >> n >> m;
	int sum = 0;
	for (int i = 0; i < m; i++) cin >> a, sum += a;
	if (sum > n) return cout << -1 << endl, 0;
	cout << n - sum << endl;
	return 0;
}
