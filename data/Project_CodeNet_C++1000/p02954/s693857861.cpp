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
        string s; cin >> s;
        int n = sz(s);
        vector<int> a(n, 1);
        auto apply = [&]() {
                vector<int> b(n);
                for (int i = 0; i < n; i++) {
                        if (s[i] == 'L') b[i - 1] += a[i];
                        else b[i + 1] += a[i];
                        b[i] -= a[i];
                }

                for (int i = 0; i < n; i++) a[i] += b[i];
        };


        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
                //explore R
                int l = 0, r =  0;
                while (i < n && s[i] == 'R') i++, l++;
                int j = i - 1;
                while (i < n && s[i] == 'L') i++, r++;
                ans[j] = ans[j + 1] = (l + r) / 2;
                if (l % 2 != r % 2) {
                        ans[j] += l % 2;
                        ans[j + 1] += r % 2;
                }
                i--;
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