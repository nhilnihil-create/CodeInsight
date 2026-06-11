#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
	int n;
	scanf("%d", &n);
	vector<int> p(n);
	rep(i, n) scanf("%d", &p[i]);
	int count = 0;
	rep(i, n) {
		if(p[i] != i + 1) count++;
	}
	if(count <= 2) printf("YES\n");
	else printf("NO\n");
	return 0;
}