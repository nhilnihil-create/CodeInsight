#include<bits/stdc++.h>
using namespace std;
int a[101],b[101];
int main()
{
	int n;
	cin>>n;
	int cnt=0;
	bool flag=false;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		if(a[i]==b[i])
			cnt++;
		else
			cnt=0;
		if(cnt==3)
			flag=true;
	}
	if(flag)
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}