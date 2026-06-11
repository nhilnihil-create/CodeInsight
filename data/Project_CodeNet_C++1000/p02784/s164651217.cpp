#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	//freopen("input.txt","r",stdin);
#endif

	ll h,n;
	cin>>h>>n;
	ll sum=0;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		sum+=x;
	}
	if(sum>=h)
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
	return 0;
}