#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 100;

int divisor[N];

int main()
{
	int n;	scanf("%d", &n);

	for (int i = 1; i < n; i++)
		for (int j = i; j < n; j += i)
			divisor[j]++;

	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += divisor[i];
		
	printf("%d\n", ans);
	return 0;
}
