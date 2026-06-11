#include<bits/stdc++.h>
using namespace std;
#define all(v)   v.begin(),v.end()
#define all(v) v.begin(),v.end()
#define meow ios::sync_with_stdio(0);cin.tie(0);
 
typedef long long int ll;
typedef unsigned long long int ull;
 
int main()
{
    meow;
    ll i,t,j,nl,cnt=0;
    string str;
    map<string,ll>m;
 
    cin>>t;
    while(t--)
    {
        cin>>str;
        m[str]++;
    }
    /* for(auto x:m)
     {
         cout<<x.first<<"  "<<x.second<<endl;
     }*/
    /*for(auto x:m)
        {
            v.push_back({x.second,x.first})
        }*/
	for(auto x : m)
	{
		cnt=max(cnt,x.second);
	}
 
//cout<<cnt<<"xxxxx"<<endl;
	for(auto x : m)
	{
		if(x.second==cnt)
		 cout<<x.first<<endl;
	}
}