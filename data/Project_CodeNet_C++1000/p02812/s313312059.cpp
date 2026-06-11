#include<bits/stdc++.h>
#define MOD 1000000007
#define mp make_pair
#define ll long long
#define pb push_back
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define debug cout<<"Debugging.."<<endl
using namespace std;
int main()
{
	faster;

	ll int tc=1;
	//cin>>tc;
	while(tc--)
	{
		ll int n;
		cin>>n;
		string s;
		cin>>s;
		
		int count=0;
		for(int i=0;i<n-2;i++)
		{
			if(s[i]=='A' && s[i+1]=='B' && s[i+2]=='C')
			{
				count++;
			}
		}
		
		cout<<count<<endl;

	}
}


