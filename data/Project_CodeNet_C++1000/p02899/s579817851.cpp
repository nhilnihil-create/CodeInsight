#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;
int main()
{
	int n,i,j,k;
	cin>>n;
	int a[n],b[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
		{
			b[a[i]]=i+1;
		}
	for(i=1;i<n+1;i++)
		cout<<b[i]<<" ";
}
