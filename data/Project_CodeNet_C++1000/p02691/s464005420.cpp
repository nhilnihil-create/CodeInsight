#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, ll> mp;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += mp[i - a[i]];
        mp[i + a[i]]++;
    }
    cout << sum << endl;
    return 0;
}