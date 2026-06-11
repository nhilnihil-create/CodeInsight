#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const long long MAXN = 300005;
long long N, n, a[MAXN], cnt[MAXN];
long long sum[MAXN];
long long ans[MAXN];
bool check(long long k, long long x) {
	long long pos = upper_bound(a + 1, a + n + 1, x) - a;
	return sum[pos - 1] + (n - pos + 1) * x >= k * x;
}

int main() {
	cin >> N;
	for(long long i = 1, x; i <= N; i++)
        cin >> x, cnt[x]++;
	for(long long i = 1; i <= N; i++)
        if(cnt[i])
            a[++n] = cnt[i];
	sort(a + 1, a + n + 1);
	for(long long i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i];
	long long now = 0;
	for(long long k = n; k >= 1; k--) {
		while(now < N && check(k, now + 1))
            now++;
        ans[k] = now;
	}
	for(long long i = 1; i <= N; i++)
        cout << ans[i] << endl;
    return 0;
}
