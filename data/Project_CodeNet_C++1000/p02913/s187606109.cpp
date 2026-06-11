#include <bits/stdc++.h>
using namespace::std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef array<int, 3> tri;
typedef long double ld;

template <class T> istream& operator>>(istream& I, vector<T>& v) {for (T &e: v) I >> e; return I;}
template <class T> ostream& operator<<(ostream &O, const vector<T>& v) {for (const T &e: v) O << e << ' '; return O;}



const ll A = 911382323, B = 972663749;
void _main() {
        int n; cin >> n;
        string s; cin >> s;
        vector<ll> H(n);
        H[0] = s[0];
        for (int i = 1; i < n; i++)
                H[i] = (s[i] + H[i - 1] * A) % B;

        vector<ll> P(n);
        P[0] = 1;
        for (int i = 1; i < n; i++)
                P[i] = (P[i - 1] * A) % B;


        auto ss_hsh = [&] (int i, int j) -> ll {
                if (i == 0) return H[j];
                return ((H[j] - H[i - 1] * P[j - i + 1]) % B + B) % B;
        };

        auto valid = [&](int k) -> bool {
                map<ll, int> where;
                for (int i = 0; i < n; i++) {
                        int j = i + k - 1;
                        if (j > n) break;
                        ll hash = ss_hsh(i, j);
                        if (!where.count(hash)) where[hash] = i;
                        else if (where[hash] + k - 1 < i) return 1;
                }
                return 0;
        };



        int l = 0, r = n / 2, ans = 0;
        while (l <= r) {
                int mid = (l + r) / 2;
                if (valid(mid)) l = mid + 1, ans = mid;
                else r = mid - 1;
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