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

		string s,b;
		cin>>s;
		cin>>b;
		if(s.length()!=b.length())
		cout<<"-1";
		
		else
		{
			int c=0;
			for(int i=0;i<s.length();i++)
			{
				if(s[i]!=b[i])
				c++;
			}
			cout<<c<<endl;
		}
	

	
}


