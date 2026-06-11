#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	bool ans = true;
	rep(i, n)
	{
		if (a[i] % 2 == 0)
		{
			if (a[i] % 3 != 0 && a[i] % 5 != 0)
			{
				ans = false;
			}
		}
	}
	if(ans) printf("APPROVED\n");
	else printf("DENIED\n");
	return 0;
}