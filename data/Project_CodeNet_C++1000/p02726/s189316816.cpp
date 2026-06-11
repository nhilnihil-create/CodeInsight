#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,x,y;
	cin>>n>>x>>y;
	int A[n]={0};
	int dist;
	for(int i=1;i<=n;i++)
	{
		for(int j=n;j>i;j--)
		{
			dist=min(j-i,abs(x-i)+1+abs(y-j));
			A[dist]++;
		}
	}
	for(int i=1;i<n;i++)
	{
		cout<<A[i]<<endl;
	}
}