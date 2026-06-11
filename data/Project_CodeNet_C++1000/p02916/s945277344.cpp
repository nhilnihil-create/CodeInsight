#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
	int n;
	scanf("%d", &n);

	vector<int> a(n);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, n) a[i]--; //0からスタートするようにする

	vector<int> b(n);
	rep(i, n) scanf("%d", &b[i]);

	vector<int> c(n - 1);
	rep(i, n - 1) scanf("%d", &c[i]);

	int ans = 0;
	// Bの合計
	rep(i, n)
	{
		ans += b[a[i]];
	}
	// Cの合計。
	rep(i, n - 1)
	{
		if (a[i + 1] == a[i] + 1) //料理iを食べた直後に料理i+1を食べると満足度Ciを追加で得ます
		{
			ans += c[a[i]];
		}
	}
	cout << ans << endl;
	return 0;
}