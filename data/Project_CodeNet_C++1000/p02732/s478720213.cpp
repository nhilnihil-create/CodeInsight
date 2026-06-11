#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define MAX 1e6

vector<ll> nc(MAX, 0);

void findnc() {
    nc[2] = 1;
    for (ll i = 3; i < MAX; i++) {
        nc[i] = ((i) * (i - 1)) / (ll)2;
    }
}

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    findnc();
    ll temp = 0;
    map<ll, ll>::iterator itr = mp.begin();
    while (itr != mp.end()) {
        temp += nc[itr->second];
        itr++;
    }
    for (ll i = 0; i < n; i++) {
        cout << temp - (mp[a[i]] - 1) << endl;
    }

    return 0;
}
