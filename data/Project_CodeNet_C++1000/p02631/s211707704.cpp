#include<bits/stdc++.h>
using namespace std;
int n,f,a[200005];
int main()
{
	cin>>n;
	if(n%2==1)
	{
		cout<<-1;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f^=a[i];
	}
	for(int i=1;i<=n;i++)
		cout<<(f^a[i])<<" ";
	cout<<endl;
	return 0;
}