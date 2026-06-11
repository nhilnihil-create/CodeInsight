#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
	int h, n;
	scanf("%d%d", &h, &n);
	rep(i, n) {
		int a;
		cin >> a;
		h -= a;
		if(h <= 0) {
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}