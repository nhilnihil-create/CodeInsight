# include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int n;
ll m, v, p;
vector<ll> a;

bool bin(int i) {
    ll sm = 0;
    ll k = a[i] + m;
    if (k < a[p - 1]) {
        return false;
    }
    sm += (p - 1) * m + (n - i) * m;
    for (int x = p - 1; x < i; x++) {
        sm += max(ll(0), k - a[x]);
    }
    return sm >= m * v;
}

int main() {
    cin >> n >> m >> v >> p;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    int l = p - 1;
    int r = n;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (bin(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l + 1 << endl;
    return 0;
}
