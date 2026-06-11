#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int  a[N];
int main()
{
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
int n,flag=1;
cin>>n;
for(int i=0;i<n;i++)
{
	cin>>a[i];
	if(a[i]%2==0)
	{
		if(a[i]%3!=0&&a[i]%5!=0)flag=0;
	}
}
if(flag)cout<<"APPROVED";
else cout<<"DENIED";
	return 0;
}
