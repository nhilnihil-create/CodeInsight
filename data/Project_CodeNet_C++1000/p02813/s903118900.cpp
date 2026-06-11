#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    string tmp, p, q, o;
    rep(i, n) {
        cin >> tmp;
        p += tmp;
    }
    rep(i, n) {
        cin >> tmp;
        q += tmp;
        o += to_string(i + 1);
    }
    map<string, int> m;
    int cnt = 1;
    do {
        m[o] = cnt;
        cnt++;
        // cout << o << endl;
    } while(next_permutation(o.begin(), o.end()));
    cout << abs(m[p] - m[q]) << endl;
    return 0;
}