#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n][2];
	for(int i=0;i<n;i++)
	cin>>a[i][0]>>a[i][1];
	int flag=0;
	for(int i=0;i<n-2;i++)
	{
		if(a[i][0]==a[i][1] && a[i+1][0]==a[i+1][1] && a[i+2][0]==a[i+2][1])
		{
			flag++;
			break;
		}
	}
	if(flag==0)
	cout<<"No\n";
	else
	cout<<"Yes\n";
}
