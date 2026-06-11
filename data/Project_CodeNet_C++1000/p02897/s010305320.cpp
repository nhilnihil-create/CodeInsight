#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	int odd = (n + 1) / 2; //C++だと切り下げなのを活用してる。
	double ans = (double)odd / n;
	printf("%.10f\n", ans);
	return 0;
}