#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n;
int a[maxn], b[maxn], A[maxn], B[maxn];
typedef pair<int, int> pii;
#define mp(a, b) make_pair(a, b);
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) 
		scanf("%d%d", &a[i], &b[i]);
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	if(n & 1) cout << b[n / 2 + 1] - a[n / 2 + 1] + 1 << endl;
	else cout << (b[n / 2 + 1] + b[n / 2] - a[n / 2 + 1] - a[n / 2]) + 1 << endl;
	return 0;
}