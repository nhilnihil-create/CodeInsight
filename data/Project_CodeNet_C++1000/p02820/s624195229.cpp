#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back

const int N = 100005;
int dp[N][3], n, k, R, S, P;
string T;

int rec(int x, int d) {
	if (x > n) {
		return 0;
	}
	int &ret = dp[x][d];
	if (ret != -1) return ret;
	ret = 0;
	int w = 0;
	if (d == 0 && T[x] == 's') {
		w = R;
	} else if (d == 1 && T[x] == 'p') {
		w = S;
	} else if (d == 2 && T[x] == 'r') {
		w = P;
	}
	for (int i = 0; i < 3; i++) {
		if (i != d) {
			ret = max(ret, rec(x + k, i));
		}
	}
	return ret += w;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n >> k >> R >> S >> P >> T;
    int res = 0;
    for (int i = 0; i < min(n, k); i++) {
		res += max(rec(i, 0), max(rec(i, 1), rec(i, 2)));
	}
	cout << res;
    return 0;
}
