#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n, m, a, p;
    cin >> n >> m >> a >> p;
    vector<ll> v(n);
    for (auto &i : v) {
        cin >> i;
    }
    sort(v.rbegin(), v.rend());
    int l = p - 1, r = n;
    while(r - l > 1) {
        int mid = (l + r) >> 1;
        if (v[mid] + m < v[p-1]) {
            r = mid;
            continue;
        }
        if (v[mid] == v[p-1]) {
            l = mid;
            continue;
        }
        ll u = 0;
        ll tar = v[mid] + m;
        for (int i = 0 ; i < n ; i++) {
            if (i < p - 1) {
                u += m;
            }
            else{
                u += min(max(0LL, tar - v[i]), m);
            }
        }
        if (u >= m * a) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    cout << l + 1 << '\n';
}