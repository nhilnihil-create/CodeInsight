#include<bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define mp make_pair
#define PI acos(-1)
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll i,j,k,x,y,z,m,n,t,a,b,c,l,r,q;
    cin>>n;
    vector<ll>v1(n);
    ll sum=0;
    for(i=0; i<n; i++)
    {
        cin>>v1[i];
        sum^=v1[i];
    }
     for(i=0; i<n; i++)
    {
        ll ans=sum^v1[i];
        cout<<ans<<" ";
    }
}






