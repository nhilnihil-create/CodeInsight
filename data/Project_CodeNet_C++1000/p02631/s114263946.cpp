#include<bits/stdc++.h>
using namespace std;
int a[200005];
long long sum1;
int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum1=sum1^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cout<<(sum1^a[i])<<' ';
	}
}