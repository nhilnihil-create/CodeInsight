#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int main() {
    ll n,k,i,l,sum=0; cin>>n>>k; vector<ll>a;
    if (k>=n) {cout<<0; return 0;}
    for(i=0;i<n;i++) 
    { cin>>l; a.pb(l); }
    sort(a.begin(),a.end());
    for(i=0;i<n-k;i++) {sum+=a[i];}
    cout<<sum;
	return 0;
}