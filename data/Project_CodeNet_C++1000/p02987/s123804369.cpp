#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007


void solve()
{
	string s;
	cin>>s;
	map<char,ll> mp;
	for(ll i=0;i<4;i++)
		mp[s[i]]++;
	for(auto x:mp)
	{
		if(x.second!=2)
		{
			cout<<"No";
			return;
		}
	}
	cout<<"Yes";
    return;
}

int main()
{
        fast;
        ll q;
        q=1;
        // cin>>q;
        while(q--)
        	solve();
        
        return 0;
}