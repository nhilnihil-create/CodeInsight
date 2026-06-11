#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	map<string,int>rel;
	while(n--)
	{
		string s;
		cin>>s;
		rel[s]++;
	}
	int mx=0;
	for(auto var : rel)
	{
		mx=max(mx,var.second);
	}
	for(auto var : rel)
	{
		if(var.second==mx)
		 cout<<var.first<<"\n";
	}
	return 0;
	
}