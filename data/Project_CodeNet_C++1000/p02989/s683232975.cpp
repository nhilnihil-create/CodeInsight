
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll n = 0;
    cin >> n;
    vector<ll> v(n);
    for(ll i = 0;i < n;i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());

    cout <<  v[n / 2] - v[n / 2 - 1] << endl;
    return 0;
}