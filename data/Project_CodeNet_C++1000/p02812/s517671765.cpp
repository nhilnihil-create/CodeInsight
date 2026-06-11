#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
	ll k,n,ans(0),i;
	string s;
	cin>>n>>s;
	for(i=0;i<s.size()-2;i++)
	{
		if(s[i]=='A' && s[i+1]=='B' && s[i+2]=='C')
		{
			ans++;
		}
	}
	cout<<ans;
}
