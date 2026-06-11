#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
int main()
{
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	int a[n],b[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<=min(50,m);i++)
	{
		for(j=0;j<n;j++)	b[j]=0;
		for(j=0;j<n;j++)
		{
			int l = max(0,j-a[j]);
			int r = min(n-1,j+a[j]);
			b[l]++;
			if(r+1<n)	b[r+1]--;	
		}
		for(j=1;j<n;j++)	b[j]+=b[j-1];
		for(j=0;j<n;j++)	a[j]=b[j];
	}
	for(i=0;i<n;i++)	printf("%d ",a[i]);
}
