#include <bits/stdc++.h>
using namespace::std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef array<int, 3> tri;
typedef long double ld;

template <class T> istream& operator>>(istream& I, vector<T>& v) {for (T &e: v) I >> e; return I;}
template <class T> ostream& operator<<(ostream &O, const vector<T>& v) {for (const T &e: v) O << e << ' '; return O;}




void _main() {
        int n, k; cin >> n >> k;
        vector<int> rsp(3); cin >> rsp;
        string t; cin >> t;
        string choice(n, 'X');
        int ans = 0;
        for (int i = 0; i < n; i++) {
                if (t[i] == 'r') choice[i] = 'p';
                if (t[i] == 's') choice[i] = 'r';
                if (t[i] == 'p') choice[i] = 's';
        }

        for (int i = 0; i < n; i++) {
                if (i - k >= 0 && choice[i - k] == choice[i]) {
                        choice[i] = 'X';
                } else {
                        if (choice[i] == 'r') ans += rsp[0];
                        else if (choice[i] == 's') ans += rsp[1];
                        else ans += rsp[2];
                }
        }

        cout << ans;
}



signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}
