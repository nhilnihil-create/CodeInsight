#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
using namespace std;

#define INF 1e9
#define PI 3.141592653589793238
typedef long long ll;

int main() {
    ll n,k;cin>>n>>k;
    vector<ll> v(n);
    ll ans=0;
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    for(int i=0; i<n-k; i++) ans+=v[i];

    if(n<=k) cout<<0<<endl;
    else cout<<ans<<endl;

    return 0;
}