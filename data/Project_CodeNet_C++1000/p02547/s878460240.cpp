#include <bits/stdc++.h>
#define ll long long
#include <string>
using namespace std;

int main()
{
	int n;cin>>n;bool ok=false;
	int d1[n],d2[n];
	for(int i=0;i<n;i++)
	{
		cin>>d1[i]>>d2[i];
	}
	for(int i=0;i<=n-3;i++)
	{
		if(d1[i]==d2[i]&&d1[i+1]==d2[i+1]&&d1[i+2]==d2[i+2])
		{
			ok=true;
			break;
		}
	}
	if(ok) cout<<"Yes"<<"\n";
	else cout<<"No"<<"\n";
}
