#include <bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define l first
#define r second
#define all(x) x.begin(), x.end()
#define fori(a, b, step) for (int i = a; i < b; i += step)
#define forj(a, b, step) for (int j = a; j < b; j += step)
#define int long long

const int maxn = 5e5 + 1, mod = 1e9 + 7;

using namespace std;

int a[maxn];
int cnt[32];

ostream& operator<<(ostream &o, pi &pt) {
    o << pt.l << ' ' << pt.r;
    return o;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int s; cin >> s;
    int l = -1, r = 1e9;
    while (r - l > 1) {
        int md = (l + r) / 2;
        if (md * md < s)
            l = md;
        else
            r = md;
    }
    pi p1(0, 0), p2, p3;
    p2.l = p3.r = r;
    p2.r = 1; p3.l = r * r - s;
    if (r * r == s)
        p2.r = p3.l = 0;
    cout << p1 << ' ' << p2 << ' ' << p3;
    return 0;
}
