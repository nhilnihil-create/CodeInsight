#include<bits/stdc++.h>
using namespace std;
const int MOD=1000000007;
#define ll long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
int main()
{
	int i,c=1;
	string s; cin>>s;
	for(i=1;i<3;i++)
	{
		if(s[i-1]=='R')
		{
			if(s[i-1]==s[i])
			c++;
		}
	}
	if(s=="SSS")
	cout<<0<<endl;
	else
	{
		cout<<c<<endl;
		
	}

}
