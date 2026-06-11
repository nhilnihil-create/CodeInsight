#include<bits/stdc++.h>
using namespace std;

#define ran 1011

int n, k;
int a[ran];

int main() {
	scanf("%d%d", &n, &k);
	for(int i=0;i<n;i++) scanf("%d", &a[i]);
	sort(a, a+n);
	
	int ans = 0;
	for(int i=0;i<k;i++)
		ans += a[i];
	printf("%d\n", ans);
	
	return 0;
}