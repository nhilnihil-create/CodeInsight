#include<bits/stdc++.h>
#define endl '\n'
#define int long long
 
using namespace std;
 
int32_t main ()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	string s;
	cin>>s;
	int len=s.length();
	if(s[len-1]!='s')cout<<s<<'s'<<endl;
	else cout<<s<<"es"<<endl;	
	
	return 0;
}
