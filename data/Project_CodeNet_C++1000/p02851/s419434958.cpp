#include <bits/stdc++.h>
using namespace::std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef array<int, 3> tri;
typedef long double ld;

template <class T> istream& operator>>(istream& I, vector<T>& v) {for (T &e: v) I >> e; return I;}
template <class T> ostream& operator<<(ostream &O, const vector<T>& v) {for (const T &e: v) O << e << ' '; return O;}


void _main() {
        int n, k; cin >> n >> k;
        vector<int> a(n); cin >> a; a.insert(a.begin(), 0);

        map<int,vector<int>> asa;
        ll sum = 0, ans = 0;
        for (int i = 0; i <= n; i++) {
                (sum += a[i]) %= k;
                auto& cur = asa[((sum - i) % k + k) % k];
                int l = 0, r = cur.size() - 1, x = 0;
                while (l <= r) {
                        int mid = (l + r) / 2;
                        if (cur[mid] > i - k) {
                                r = mid - 1;
                                x = cur.size() - mid;
                        } else {
                                l = mid + 1;
                        }
                }

                ans += x;
                cur.emplace_back(i);
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