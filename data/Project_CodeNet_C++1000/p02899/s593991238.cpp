#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep(i, s, n) for (ll i = (ll)s; i < (ll)n; i++)
typedef long long ll;

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    pair<int, int> sdt[n];
    rep (i, n) {
        int a;
        cin >> a;
        sdt[i] = make_pair(a, i+1);
    }
    sort(sdt, sdt + n);
    rep (i, n) printf("%d ", sdt[i].second);
}