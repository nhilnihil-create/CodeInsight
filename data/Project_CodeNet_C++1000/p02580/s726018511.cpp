#include <iostream>
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define li long ll
#define pp pair<ll, ll>
#define lb lower_bound
#define ub upper_bound
#define mk make_pair
#define pb push_back
#define llp(i, x, n) for (ll i = x; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define fr first
#define ss second
#define mod 1000000007
using namespace std;
int main()
{
	fast;
    ll h,w,m;
    cin>>h>>w>>m;
    unordered_map<ll,ll> um1,um2;
    unordered_map<string,bool> res;
    while(m--)
    {
    	ll a,b;
    	cin>>a>>b;
    	string s;
    	s+=to_string(a);
    	s+=to_string(b);
    	res[s]=true;
    	um1[a]++,um2[b]++;
    }
    ll m1=-1,m2=-1;
    vector<int> v1,v2;
    for(auto it:um1)
    {
    	m1=max(m1,it.ss);
    }
    for(auto it:um2)
    {
    	m2=max(m2,it.ss);
    }
    for(auto it:um1)
    {
    	if(it.ss==m1)
    	v1.pb(it.fr);
    }
    for(auto it:um2)
    {
    	if(it.ss==m2)
    	v2.pb(it.fr);
    }
    int f=0;
    for(int i=0;i<v1.size();i++)
    {
    	string str;
    	for(int j=0;j<v2.size();j++)
    	{
    		str+=to_string(v1[i]);
    		str+=to_string(v2[j]);
    		if(res[str]==false)
    		{
    			f=1;
    			break;
    		}
    		str="";
    	}
    	if(f==1)
    	break;
    }
    if(f==1)
    cout<<m1+m2<<endl;
    else
    cout<<m1+m2-1<<endl;
}