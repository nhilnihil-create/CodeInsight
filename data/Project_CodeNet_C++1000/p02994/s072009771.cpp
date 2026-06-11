#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1001001001;

int main() {
    int n, l;
    cin >> n >> l;
    P p;
    int tot = 0;
    rep(i, n) {
        tot += l + i;
    }
    int samin = INF;
    int ans = 0;
    rep(i, n) {
        int aji = tot - (l+i);
        int sa = abs(l+i);
        if (sa < samin) {
            ans = aji;
            samin = sa;
        }
    }
    cout << ans << endl;
    return 0;
}