#include<bits/stdc++.h>
using namespace std;
int n,a[400001];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],a[0]^=a[i];
	for(int i=1;i<=n;i++)cout<<(a[0]^a[i])<<' ';
}