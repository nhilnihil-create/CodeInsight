#include <bits/stdc++.h>
using namespace::std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef array<int, 3> tri;
typedef long double ld;

template <class T> istream& operator>>(istream& I, vector<T>& v) {for (T &e: v) I >> e; return I;}
template <class T> ostream& operator<<(ostream &O, const vector<T>& v) {for (const T &e: v) O << e << ' '; return O;}



void _main() {
        string s, t; cin >> s >> t;
        vector<vector<int>> where(26);
        for (int i = 0; i < s.size(); i++) {
                where[s[i] - 'a'].emplace_back(i);
        }

        ll  last = -1, copy = 1;
        for (int i = 0; i < t.size(); i++) {
                auto a = where[t[i] - 'a'];
                if (a.empty()) {
                        cout << -1;
                        return;
                }

                int l = 0, r = a.size() - 1, here = -1;
                while (l <= r) {
                        int mid = (l + r) / 2;
                        if (a[mid] > last) here = a[mid], r = mid - 1;
                        else l = mid + 1;
                }


                if (here < 0) {
                        last = a.front();
                        copy++;
                } else last = here;
        }

        cout << (copy - 1) * (ll) s.size() + last + 1;
}



signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}