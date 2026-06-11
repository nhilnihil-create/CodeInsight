#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
//		freopen("in1.txt", "r", stdin);
//		freopen("in1.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	int a[n];
	for (int& x : a) cin >> x;
	sort(a, a+n);
	int ans = 0;
	for (int i=0; i+2<n; i++) {
		for (int j=i+1; j+1<n; j++) {
			if (a[i] == a[j]) continue;
			for (int k=j+1; k<n; k++) {
				if (a[j] == a[k]) continue;
				if (a[i] + a[j] > a[k]) ans++;
			}
		}
	}
	cout << ans << '\n';
}