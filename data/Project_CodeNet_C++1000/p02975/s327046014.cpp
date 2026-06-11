#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n; cin >> n;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    ll num = 0;
    for(auto v : a) num = num ^ v;
    if(!num) cout << "Yes" << endl;
    else cout << "No" << endl;
}