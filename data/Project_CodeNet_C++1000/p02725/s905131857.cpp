#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll k, n;
    cin>> k >> n;

    vector<ll> a(2*n);
    vector<ll> dis(n+1);

    for(int i=0; i<n; i++){
        cin>>a[i];
        a[i+n] = a[i]+k;
    }

    ll ans = 1e18;
    for(int i=0; i<n; i++){
        ans = min(ans, abs(a[i+n-1] - a[i]));
    }
    cout<< ans <<endl;
    return 0;
}