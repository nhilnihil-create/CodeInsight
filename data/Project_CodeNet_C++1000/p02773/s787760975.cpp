#include<bits/stdc++.h>
#define ll long long int
#define ff first
#define ss second
#define eps 1e-9

using namespace std;

int main()
{

    ll t,n,m,f,a,b,c,l,r,q,k,x,y,z,ans,mn,mx,sum=0;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<string,ll> mp;
    string exp;
    cin>>n;

    mx = 0;
    for(int i=0;i<n;i++)
    {
        cin>>exp;
        mp[exp]++;
        mx = max(mp[exp],mx);
    }

    for(auto it= mp.begin();it!=mp.end();it++)
    {
        if(it->second == mx)
        {
            cout<<it->first<<endl;
        }
    }




}
