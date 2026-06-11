#include <bits/stdc++.h>

using namespace std;
typedef map<const long long, long long> lll;

long long n, k, a[200005], psfront[200005], pslast[200005], summ, cnt, targ;
lll lis;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		a[i] = (a[i] - 1 + k) % k;
	}
	psfront[0] = 0;
	for (int i=1; i<=n; i++) {
		psfront[i] = (psfront[i - 1] + a[i - 1]) % k;
//		cout << "Front of " << i << " is " << psfront[i] << endl;
	}
	pslast[0] = 0;
	lis[0] = 1;
	for (int i=1; i<n; i++) {
		pslast[i] = (pslast[i - 1] + a[n - i]) % k;
//		cout << "Last of " << i << " is " << pslast[i] << endl;
		lis[pslast[i]]++;
	}
	for (int i=0; i<=n-k; i++) lis[pslast[i]]--;
	summ = psfront[n];
	for (int i=0; i<n; i++) {
		targ = (summ - psfront[i] + k) % k;
		cnt += lis[targ];
//		cout << "Cumulative count = " << cnt << endl;
		lis[pslast[n - 1 - i]]--;
		if (n - k - i >= 0) lis[pslast[n - k - i]]++;
	}
	cout << cnt << endl;
}