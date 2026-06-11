
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = s.length();
    int rec = 0, chg = 100;
    for (int i = 0; i < n; ++i) {
        int v = s[i] - '0';
        int nr = min(rec, chg) + v;
        int nc = min(rec + 1 + 10 - v, chg - 1 + 10 - v);
        rec = nr;
        chg = nc;
    }
    cout << min(rec, chg) << endl;

    return 0;
}

