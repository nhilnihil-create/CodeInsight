#include <bits/stdc++.h>
using namespace std;

#define ll long long 

int main() {
    ios::sync_with_stdio(0); 

    int n; cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    map<int, ll> mp; 
    for (auto x : a) mp[x]++;

    ll total = 0; 
    for (auto x : mp) {
        total += max(0LL, x.second * (x.second - 1)/2);
    }

    for (auto x : a) {
        ll curr = total;
        curr -= max(0LL, mp[x] * (mp[x] - 1) / 2);
        curr += max(0LL, (mp[x] - 1) * (mp[x] - 2) / 2);
        cout << curr << endl;
    }

    return 0; 
}

