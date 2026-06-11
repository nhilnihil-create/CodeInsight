#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int main(){
    ll k,n,i,l,m; vector<ll>a;
    cin>>k>>n;
    for(i=0;i<n;i++) {cin>>l; a.pb(l);}
    l=a[n-1]-a[0];
    for(i=1;i<n;i++)
    {
        m=a[i-1]+(k-a[i]);
        l=min(l,m);
    }
    cout<<l;
    return 0;
}
