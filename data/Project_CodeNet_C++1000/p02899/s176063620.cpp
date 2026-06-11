#include<bits/stdc++.h>
using namespace std;

#define FastRead        ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl            "\n"
#define sq(x)           ((x)*(x))
#define pi              acos(-1.0)
#define NUM             1000005

typedef long long ll;


int main()
{
    FastRead

    ll n,x=0,y=0,ans=0;

    cin>>n;

    map<ll,ll>mp;

    for(ll i=1;i<=n;i++)
    {
        ll temp;
        cin>>temp;

        mp[temp] = i;
    }

    for(auto it:mp)
        cout<<it.second<<" ";
}
