#include<bits/stdc++.h>
using namespace std;
int n,k,a[200005];
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>k)
		{
			if(a[i]>a[i-k])cout<<"Yes\n";
			else cout<<"No\n";
		}
	}
	return 0;
}