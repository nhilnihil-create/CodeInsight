#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    map<ll,ll> mp;
    for(int i = 0; i < n; i++)mp[a[i] - i]++;

    ll cnt = 0;
    for(int i = 0; i < n; i++) {
        cnt += mp[-a[i] - i];
    }
    cout << cnt << endl;
}