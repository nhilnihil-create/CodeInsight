#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int a[100005], pn[100005];

int main() {
    int n, m;
    cin >> n >> m;

    int ac = 0, pena = 0;
    rep(i, m) {
        int p;
        cin >> p;
        p--;
        string s;
        cin >> s;

        if (s == "WA" && a[p] == 0) pn[p]++;
        if (s == "AC" && a[p] == 0) {
            ac++;
            a[p] = 1;
            pena += pn[p];
        }
    }

    cout << ac << ' ' << pena << endl;
    return 0;
}
