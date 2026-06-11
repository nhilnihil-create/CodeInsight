#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
const int N=1e5+3;
ll a[N];
int main()
{
    ft
    ll t,i,j,n,m,l,r,k,q;
    cin>>n>>k>>q;
    for(i=1;i<=n;i++)
    {
        a[i]=k;
    }
    l=0;
    while(q--)
    {
        cin>>r;
        a[r]++;
        l++;
    }
    for(i=1;i<=n;i++)
    {
        a[i]-=l;
    }
    for(i=1;i<=n;i++)
    {
        if(a[i]<=0)
        {
            cout<<"No\n";
        }
        else
        {
            cout<<"Yes\n";
        }
    }
    return 0;
}