#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9+7;
const int N = 200005;

int n, a[N];
int ans[N];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);

	vector<int> pos;
	for(int i = n; i >= 1; i--) {
		int cnt = 0;
		for(int j = i + i; j <= n; j += i) {
			cnt += ans[j];
		}
		if(cnt % 2 != a[i] % 2) {
			ans[i] = 1;
		}
		if(ans[i]) pos.push_back(i);
	}
	reverse(pos.begin(), pos.end());

	printf("%d\n", (int)pos.size());

	for(int x : pos) printf("%d ", x);
	printf("\n");
}
