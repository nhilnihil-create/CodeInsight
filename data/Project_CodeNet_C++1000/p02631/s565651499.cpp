#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll GCD(ll a, ll b){ return a ? GCD(b % a, a) : b; }
int main(){
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    ll xsum = 0;
    for(int i=0; i<n; i++){
        xsum = xsum ^ a[i];
    }
    for(int i=0; i<n; i++){
        ll ans = xsum ^ a[i];
        cout<<ans<<" "; 
    }
    cout<<endl;
}