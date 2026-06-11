#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
int main() 
{
	 ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     
		string s;
		cin>>s;
		int ans=0;
		string s1,s2="";
		for(int i=0;i<(int)s.length();i++)
		{
			s1+=s[i];
			if(s1==s2)
			continue;
			
			s2=s1;
			s1="";
			ans++;
			
			
		}
		cout<<ans<<"\n";
			
				 
	
}
