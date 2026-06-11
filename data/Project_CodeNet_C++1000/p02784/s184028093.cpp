#include <bits/stdc++.h>
using namespace std;
int main()
{
	int h,n,sum=0,t;
	cin>>h>>n;
	for(int i=0;i<n;++i)
	{
		cin>>t;
		sum+=t;
	}
	if(sum>=h) cout<<"Yes\n";
	else cout<<"No\n"; 
	return 0;
} 