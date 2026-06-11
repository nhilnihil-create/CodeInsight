#include <bits/stdc++.h>
using namespace std;

const int N = 3005;

int dp[N*2], n, A[N], B[N], id[N], T;

int main() {
	scanf("%d %d", &n, &T);
	for (int i = 1; i <= n; i ++) scanf("%d %d", &A[i], &B[i]), id[i] = i;
    memset(dp, -1, sizeof dp);
    dp[0] = 0;
    sort(id+1, id+n+1, [](int x, int y){return A[x] < A[y];});
    for (int j = 1; j <= n; j ++) {
		int o = id[j];
        int a = A[o], b = B[o];
		for (int i = T-1; i >= 0; i --) if (dp[i] >= 0) dp[i+a] = max(dp[i+a], dp[i] + b);
    }
    int ans = *max_element(dp, dp + N*2);
    cout << ans << endl;
	return 0;
}
