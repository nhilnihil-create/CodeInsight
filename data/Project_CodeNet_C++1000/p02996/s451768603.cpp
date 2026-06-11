#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    P p[n];
    rep(i, n) cin >> p[i].second >> p[i].first;
    sort(p, p + n);

    int t = 0;
    rep(i, n) {
        t += p[i].second;
        if (t > p[i].first) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}
