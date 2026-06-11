#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int a[200000];
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a+n, greater<int>());
	long long sum = a[0];
	int j = 0;
	for(int i = 1; i < n - 1; i++) {
		if(i & 1) j++;
		sum += a[j];
	}
	if(n == 1) sum = 0;
	printf("%lld\n", sum);
}