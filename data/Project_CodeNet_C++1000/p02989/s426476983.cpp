#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
int main()
{
    ft
    ll t,i,j,n,m,l,r;
    cin>>n;
    ll a[n+1];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    cout<<a[n/2]-a[(n/2)-1]<<"\n";
    return 0;
}