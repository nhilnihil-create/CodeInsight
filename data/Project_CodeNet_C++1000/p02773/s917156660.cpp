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

	int n;
	cin>>n;


	

	

	map<string,int> mp;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		mp[s]++;
		
	}

	int c=INT_MIN;

	for(auto i:mp)
	{
		c=max(c,i.second);
	}

	

	for(auto i:mp)
	{
		if(i.second==c)
		{
			cout<<i.first<<endl;
		}
		
	}



	return 0;
}