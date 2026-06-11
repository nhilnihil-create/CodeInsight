#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define ull unsigned long long int 
#define pb push_back
#define xx first
#define yy second
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ull t;
	t=1;
	while(t--)
	{
		string s;
		cin>>s;
		
		ll n=s.size();
		
		if(s[n-1]=='s')
			s+="es";
		else
			s+="s";
			
		cout<<s;
	}
}