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
        int n;
        cin >> n;
        int a[n + 1];
        for (int i = 1; i <= n; i++) cin >> a[i];


        vector<int> choice(n + 1);
        for (int i = n; i >= 1; i--) {
                if (i * 2 > n) {
                        choice[i] = a[i];
                } else {
                        int sum = 0;
                        int ts = 2;
                        while (ts * i <= n) {
                                (sum += choice[i * ts]) %= 2;
                                ts++;
                        }
                        if (sum != a[i]) choice[i] = 1;
                }
        }

        vector<int> ans;
        for (int i = 1; i <= n; i++) {
                if (choice[i]) ans.emplace_back(i);
        }

        cout << ans.size() << '\n' << ans;
}



signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}