/* **********************************JAI SAI RAM ************************************* */
//HELP IN CODEFORCES ROUND 641
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void  solve()
{
    ll n,i,j,k,l,m,o,q,r,t,x,y,a,b;
    ll ans=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        ans+=(n-i+1)*(i);
        if(i>=2)
        {
            cin>>j>>k;
            if(j>k)
            swap(j,k);
            ans-=(j*(n-k+1));
        }
    }
    cout<<ans<<endl;
}
int main()
{
    ll t;
    t=1;
        while(t--)
    {
        solve();
    }
    return 0;
}
