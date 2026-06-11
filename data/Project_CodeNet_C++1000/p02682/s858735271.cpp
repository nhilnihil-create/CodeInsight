#include <bits/stdc++.h>  
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define pl pair<ll,ll>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define vl vector<ll>
#define mod 1000000007


int main()
{
    ll a,b,c,k;cin>>a>>b>>c>>k;
    if(k<=a)
    cout<<k<<"\n";
    else
    {
        ll ans=0;
        if(k>a)
        {
            ans+=a;
            k-=a;
        }
        if(k>b)
        {
            k-=b;
            if(k<=c)
            ans-=k;
        }
        cout<<ans<<"\n";
    }

}