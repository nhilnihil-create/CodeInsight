#include<bits/stdc++.h>
using namespace std;

#define i64 long long int
#define ran 202202

int n;
int a[ran];

int cmp(int a, int b){
	return a>b;
}

int main() {
	scanf("%d", &n);
	
	i64 ans = 0LL;
	for(int i=0;i<n;i++) scanf("%d", &a[i]);
	sort(a, a+n, cmp);
	for(int i=1;i<n;i++)
		ans += a[i/2];
	printf("%lld\n", ans);
	
	return 0;
}