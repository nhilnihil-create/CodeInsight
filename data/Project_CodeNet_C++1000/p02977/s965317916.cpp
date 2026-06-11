#include <bits/stdc++.h>
#define lowbit(x) ((x)&(-(x)))
using namespace std;

int n;

int main()
{
	cin >> n;
	if(lowbit(n) == n){
		puts("No");
		return 0;
	}
	puts("Yes");
	for(int i = 2; i < n; i += 2){
		printf("1 %d\n", i), printf("%d %d\n", i, i+1);
		printf("1 %d\n", i+n+1), printf("%d %d\n", i+n+1, i+n);
	}
	printf("3 %d\n", n+1);
	if(n&1) return 0;
	int p = lowbit(n);
	printf("%d %d\n", p+n+1, n);
	printf("%d %d\n", n^p, n+n);
	
	return 0;
}