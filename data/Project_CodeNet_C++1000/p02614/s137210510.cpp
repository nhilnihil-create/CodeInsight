#include <bits/stdc++.h>
using namespace std;
#define test() int t; cin>>t; while(t--)
#define ll long long int
int mod = 1e9 + 7;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int h, w, k;
	cin >> h >> w >> k;
	vector<string> a(h);
	for (int i = 0; i < h; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for (int m1 = 0; m1 < (1 << h); m1++) {
		for (int m2 = 0; m2 < (1 << w); m2++) {
			int b = 0;
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					if (((m1 >> i) & 1) == 0 && ((m2 >> j) & 1) == 0 && a[i][j] == '#')	b++;
				}
			}
			if (b == k)	ans++;
		}
	}
	cout << ans << endl;
	return 0;
}