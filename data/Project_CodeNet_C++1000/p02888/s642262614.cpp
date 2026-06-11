#include <bits/stdc++.h>
using namespace::std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef array<int, 3> tri;
typedef long double ld;

template <class T> istream& operator>>(istream& I, vector<T>& v) {for (T &e: v) I >> e; return I;}
template <class T> ostream& operator<<(ostream &O, const vector<T>& v) {for (const T &e: v) O << e << ' '; return O;}



void _main() {
        int n; cin >> n;
        vector<int> sticks(n); cin >> sticks;
        sort(all(sticks));
        //a, b, c [a <= b <= c]
        //a + b > c


        //a + b
        int ans = 0;
        for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                        int a = sticks[i];
                        int b = sticks[j];
                        //c < a + b
                        //j ...
                        int l = j + 1, r = n - 1, where = j;
                        while (l <= r) {
                                int mid = (l + r) / 2;
                                int c = sticks[mid];
                                if (c < a + b)  {
                                        where = mid;
                                        l = mid + 1;
                                } else {
                                        r = mid - 1;
                                }
                        }
                        ans += where - j;
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