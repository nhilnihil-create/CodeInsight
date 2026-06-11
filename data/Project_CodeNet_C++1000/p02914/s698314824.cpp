#include <bits/stdc++.h>

typedef long long cc;
#define pb push_back
using namespace std;
const int N = 100005;
const int P = 105;
int tot, n, d[N], res[N];
cc a[N], sum;
bitset <N> dp[P];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum ^= a[i];
        res[i] = 1;
	}
	for (int i= 62; i >= 0;i--) {
        if (!((sum >> i) & 1)) {
            ++tot;
            for (int j = 1; j <= n; j++) {
                dp[tot][j] = (a[j] >> i) & 1;
            }
        }
	}
	for (int i = 62; i >= 0; i--) {
        if (((sum >> i) & 1)) {
            ++tot;
            for (int j = 1; j <= n; j++) {
                dp[tot][j] = (a[j] >> i) & 1;
            }
        }
	}

	for (int i = 1; i <= tot; i++) {
		dp[i][0] = 1;
		for (int j = 1; j < i; j++) {
			if (dp[i][d[j]]) {
                dp[i] ^= dp[j];
			}
		}
		d[i] = 1;
		while (d[i] <= n && !dp[i][d[i]]) {
            ++d[i];
		}
		if (d[i] <= n) {
			for (int j = 1; j < i; j++) {
				if (dp[j][d[i]]) {
                    dp[j] ^= dp[i];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
        res[i] = 1;
	}
	for (int i = 1; i <= tot; i++) {
		if (d[i] <= n && dp[i][0]) {
                res[d[i]] = 2;
		}
	}
    int cnt2 = 0;
    for (int i = 1; i <= n; i++) {
        cnt2 += (res[i] == 2);
    }
    if (cnt2 == n || cnt2 == 0) {
        cc mn = a[1];
        int idx = 1;
        for (int i = 1; i <= n; i++) {
            if (a[i] < mn) {
                mn = a[i];
                idx = i;
            }
        }
        res[idx] = 3^res[idx];
    }
    cc sum1 = 0, sum2 = 0;
    for (int i = 1; i <= n; i++) {
        if (res[i] == 1) {
            sum1 ^= a[i];
        } else {
            sum2 ^= a[i];
        }
    }
    cout << sum1 + sum2;
	return 0;
}
