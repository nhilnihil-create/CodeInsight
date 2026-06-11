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
    ll i,j,k,x,y,z,m,n,t,a,b,c,l,r;
    cin>>n;
    vector<ll>v(n);
    for(i=0; i<n; i++)
        cin>>v[i];
    sort(v.rbegin(),v.rend());
    ll ans=0;
    ans+=v[0];
    i=1;
    x=0;
    n-=2;
    while(n--)
    {
        ans+=v[i];
        x++;
        if(x==2)
        {
            i++;
            x=0;
        }
    }
    cout<<ans<<'\n';
}




