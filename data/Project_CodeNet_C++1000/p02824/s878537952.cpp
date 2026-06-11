#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	int n, m, v, p;
	scanf("%d %d %d %d", &n, &m, &v, &p);
	vector<ll> arr(n);
	for (int i = 0; i < n; ++i) scanf("%lld", &arr[i]);
	sort(begin(arr), end(arr));
	vector<ll> psums(n + 1);
	for (int i = 0; i < n; ++i) psums[i + 1] = psums[i] + arr[i];
	int ans = 0;
	for (int i = 0; i < n; ++i) {
//		printf("checking %d\n", i);
		// can the ith problem be included?
		auto firstExc = upper_bound(begin(arr), end(arr), arr[i] + m);
		int unbeatCt = distance(firstExc, arr.end());
		if (unbeatCt >= p) {
//			printf("%d beats boosted %d\n", unbeatCt, i);
			continue;
		}
		// strat is, we vote for top p - 1 + problem i
		// then ask if we can throw the other votes elsewhere
		auto firstExcUnmod = upper_bound(begin(arr), end(arr), arr[i]);
		if (distance(firstExcUnmod, arr.end()) < p) {
//			printf("%d wins unboosted\n", i);
			++ans;
			continue;
		}
		// now WLOG i is not in the top p - 1 at first
		ll remPerJudge = v - p;
		if (remPerJudge <= 0) {
//			printf("%d wins if boosted right", i);
			++ans;
			continue;
		}
//		printf("%d vpj left\n", remPerJudge);
		// for a problem p such that v_i < v_p <= v_i + m, count v_i + m - v_p
		// for a problem p such that v_p <= v_i, count m
		ll firstExcStart = distance(arr.begin(), firstExcUnmod);
//		printf("fex %lld\n", firstExcStart);
		ll totalFromBetween = psums[n - p + 1] - psums[firstExcStart];
		ll checkCount = (n - p - firstExcStart + 1) * (arr[i] + m) - totalFromBetween; 
		ll totalFromBehind = max(0LL, (firstExcStart - 1) * m);
//		printf("tfbet cc tfbeh %lld %lld %lld\n", totalFromBetween, checkCount, totalFromBehind);
		if (totalFromBehind + checkCount >= m * remPerJudge) {
//			printf("%d wins with check count %lld\n", i, totalFromBehind + checkCount);
			++ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}
