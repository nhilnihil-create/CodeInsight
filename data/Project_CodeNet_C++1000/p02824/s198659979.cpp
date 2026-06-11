#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define all(a) (a).begin(), (a).end()

#define ll long long

int n, p, v;
ll m, a[100000];

bool ok(int x) {
    ll y = m*(v-1);
    int z = 0;
    vector<ll> b;
    for (int i = 0; i < n; i++) {
        if (i == x) continue;
        if (a[i] > a[x]+m) {
            y -= m;
            z++;
            if (z > p-1) return 0;
        } else {
            ll w = min(m, a[x]+m-a[i]);
            y -= w;
            if (a[x]+m > a[i]) b.pb(m-w);
        }
    }
    sort(all(b));
    for (int i=0; i<p-1-z && i<b.size(); i++) {
        y -= b[(int)b.size()-i-1];
    }
    return y <= 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> v >> p;
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);
    int lo = 0, hi = n + 1;
    while (hi-lo > 1) {
        int mi = (lo+hi)/2;
        if (ok(n - mi)) lo = mi;
        else hi = mi;
    }
    cout << lo;
    return 0;
}
