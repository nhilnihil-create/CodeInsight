#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	if(n<m) swap(n,m);
	printf("%d\n",(k+n-1)/n);
	return 0;
}