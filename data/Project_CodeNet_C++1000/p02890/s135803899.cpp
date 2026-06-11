#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int cnt[N], n;
int a[N], ans[N];

int main() {
	cin>>n;for(int i = 1; i <= n; i++) {
		int t; scanf("%d", &t);
		cnt[t]++;
	}
	for(int i = 1; i <= n; i++) if (cnt[i]) {
		a[++a[0]] = cnt[i];
	}
	sort(a + 1, a + 1 + a[0]);
	int sum = 0;
	for(int cs = 1, j = 0; cs <= n; cs++) {
		while(j < a[0] && a[j + 1] < cs){
			j++;
			sum += a[j];
		}
		int t = sum / cs + a[0] - j;
		ans[t] = max(ans[t], cs);
	}
	for(int i = n; i; i--) ans[i] = max(ans[i + 1], ans[i]);
	for(int i = 1; i <= n; i++) printf("%d\n", ans[i]);
}