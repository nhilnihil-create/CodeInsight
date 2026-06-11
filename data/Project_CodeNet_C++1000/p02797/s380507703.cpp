#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=1e9;
int main()
{
	int n,k,s;
	cin>>n>>k>>s;
	if(s==MAXN) 
	{
		for(int i=1;i<=k;i++)
			printf("%d ",MAXN);
		for(int i=k+1;i<=n;i++)
			printf("%d ",1);
	}
	else {
		for(int i=1;i<=k;i++)
			printf("%d ",s);
		for(int i=k+1;i<=n;i++)
			printf("%d ",MAXN);
	}
}