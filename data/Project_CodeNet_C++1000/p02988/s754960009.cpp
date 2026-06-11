#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
int main()
{
    ft
    ll t,i,j,n,m,l=0,r;
    cin>>n;
    ll a[n+2];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=1;i<n-1;i++)
    {
        ll b[3]={a[i],a[i-1],a[i+1]};
        sort(b,b+3);
        if(b[1]==a[i])
        {
            l++;
        }
    }
    cout<<l<<"\n";
    return 0;
}

