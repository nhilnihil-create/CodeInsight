#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int main() {
    ll n,i,l; cin>>n; set<ll>a;
    for(i=0;i<n;i++) {cin>>l; a.insert(l);}
    if (n==a.size()) {cout<<"YES";} 
    else {cout<<"NO";}
	return 0;
}