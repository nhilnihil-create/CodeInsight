#include <iostream>
#include <algorithm>
#include <map>
const int maxN = 2e5 + 10;
using namespace std;

int n, k;
int a[maxN];
map<long long, long long> cnt;

int main()
{
	cin >> n >> k;
	cnt[0] = 1;

	long long ans = 0;
	for (long long i = 1; i <= n; ++i)
    {
        long long x;
        cin >> x;
		a[i] = (a[i - 1] + x - 1) % k;
		if (i >= k)
            cnt[a[i-k]]--;
		ans += cnt[a[i]]++;
	}

	cout << ans << '\n';

	return 0;
}
