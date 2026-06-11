#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int main() {
    ll n,l=1e6,c=0,i; cin>>n; ll a[n];
    for(i=0;i<n;i++) 
    {
        cin>>a[i];
        l=min(l,a[i]);
        if (l==a[i]) {c++;}
    }
    cout<<c;
	return 0;
}