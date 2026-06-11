#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k=1,m=0;
	scanf("%d",&n);
	while (k*k<n)
	{	
		m=(n/k-k)*2+m+1;
		if (n%k==0) m-=2;
		k++;
	 
	}

	printf("%d",m);
	return 0;
 }