#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll i,j,k,n,m,s;
    cin>>n;s=0;
    ll a[n+5];
    for(i=0;i<n-1;i++) cin>>a[i];
    s=a[0];
    for(i=1;i<n-1;i++) s+=min(a[i],a[i-1]);
    cout<<s+a[n-2];
}
