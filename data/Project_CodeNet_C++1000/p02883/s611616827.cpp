#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n, k;
	cin >> n >> k;
	vector<long long> a(n), f(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> f[i];
	sort(a.begin(), a.end());
	sort(f.rbegin(), f.rend());
	long long l = -1;
	long long r = 1e12;
	while(abs(l - r) > 1) {
		long long mid = (l + r) / 2;
		bool ok = [&] {
			long long s = 0;
			for(int i = 0; i < n; i++) {
				s += max(0LL, a[i] - mid / f[i]);
			}
			return s <= k;
		}();
		if(ok) r = mid;
		else l = mid;
	}
	cout << r << endl;
	return 0;
}
