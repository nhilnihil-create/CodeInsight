//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define in(x, l, r) (ll)(l) <= (x) && (x) < (ll)(r)

int main() {
    int N;
    cin >> N;
    int maxlen = 0;
    int tmplen = 0;
    rep(i,0,N) {
        int D1, D2;
        cin >> D1 >> D2;
        if (D1 == D2) {
            tmplen++;
            maxlen = max(maxlen, tmplen);
        } else {
            tmplen = 0;
        }
    }
    if (maxlen >= 3) cout << "Yes" << endl;
    else cout << "No" << endl;
}