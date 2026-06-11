#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 2e5 + 5;
const int M = 1e6 + 5;
int n;
int a[N], d[M];

int main() {
	cin>>n;
	
	for (int i = 1; i <= n; i++) {
		cin>>a[i];
		if (!d[a[i]]) {
			for (int j = a[i]; j <= 1e6; j += a[i]) 
			d[j]++;
		}
		else {
			d[a[i]]++;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) if (d[a[i]] == 1) ans++;
	printf("%d\n", ans);
}
