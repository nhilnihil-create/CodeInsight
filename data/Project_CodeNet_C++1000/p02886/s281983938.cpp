#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
	int n;
	scanf("%d", &n);
	int ans = 0;
	vector<int> vec(n);
	rep(i, n) scanf("%d", &vec[i]);
	rep(i, n) {
		for(int j = i + 1; j < n; j++)
		ans += vec[i] * vec[j];
	}
	printf("%d\n", ans);
	return 0;
}