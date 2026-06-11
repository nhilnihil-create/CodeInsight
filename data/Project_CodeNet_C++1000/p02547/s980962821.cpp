#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;cin>>n;
	int i;
	int a[n+5],b[n+5];
	for(i=0;i<n;i++)
	cin>>a[i]>>b[i];
	for(i=2;i<n;i++)
	if(a[i]==b[i]&&a[i-1]==b[i-1]&&a[i-2]==b[i-2])
	break;
	i==n?cout<<"No"<<endl:cout<<"Yes"<<endl;
	return 0;
}