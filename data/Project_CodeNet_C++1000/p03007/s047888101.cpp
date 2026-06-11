#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	reverse(a,a+n);
	int ans=0;
	for (int i = 0; i < n; ++i)
	{
		ans+=abs(a[i]);
	}
	if (a[0]<0)
	{
		ans-=2*abs(a[0]);
	}
	else if (a[n-1]>0)
	{
		ans-=2*abs(a[n-1]);
	}
	cout<<ans<<endl;
	int now=1;
	while (a[now]>0)
	{
		cout<<a[n-1]<<" "<<a[now]<<endl;
		a[n-1]-=a[now];
		++now;
	}
	while (now<n)
	{
		cout<<a[0]<<" "<<a[now]<<endl;;
		a[0]-=a[now];
		++now;
	}
	return 0;
}
