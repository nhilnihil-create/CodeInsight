#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int main() {
    ll n,i,l=1e4,m=0,c=1e9,j,s; cin>>n; 
    vector<ll>a; 
    for(i=0;i<n;i++) 
    {cin>>l; a.pb(l); }
    sort(a.begin(),a.end());
    for(i=a[0];i<=a[n-1];i++)
    { s=0;
        for(j=0;j<n;j++)
        {
            s+=(i-a[j])*(i-a[j]);
        }
        c=min(c,s);
    }
    cout<<c;
	return 0;
}