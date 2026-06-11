#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    ll n; cin >> n;
    vector<ll> a(n);
    for(ll i=0; i<n; ++i){cin >> a[i];}
    bool ok = true;
    sort(a.begin(), a.end());
    for(ll i=0; i<n; ++i){
        if(a[i]==a[i+1]){ok = false;}
    }
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}