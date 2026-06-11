#include "bits/stdc++.h"
using namespace std;

const int N=1e2+20;

int n,m,a[N];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);

	sort(a,a+n);
	int sum=accumulate(a,a+n,0);
	if(4*m*a[n-m]<sum) printf("No");
	else printf("Yes");
}