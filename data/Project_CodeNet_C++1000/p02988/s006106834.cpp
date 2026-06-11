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
	rep(i, n - 2) {
		if(p[i] > p[i + 1] && p[i + 1] > p[i + 2]) count++;
		else if(p[i] < p[i + 1] && p[i + 1] < p[i + 2]) count++;
	}
	printf("%d\n", count);
	return 0;
}