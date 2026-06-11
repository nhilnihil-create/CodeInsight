#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vi>;
using ll = long long;

int main() {
    int n;
    n = 5;
    vi a(n);
    rep(i, n) cin >> a.at(i);

    rep(i, n) {
        if (a.at(i) == 0) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    //rep (i, n) {
    //    cout << a.at(i) << endl;
    //}
}