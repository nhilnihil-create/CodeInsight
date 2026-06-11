/*
                `-/oo+/-   ``
              .oyhhhhhhyo.`od
             +hhhhyyoooos. h/
            +hhyso++oosy- /s
           .yoooossyyo:``-y`
            ..----.` ``.-/+:.`
                   `````..-::/.
                  `..```.-::///`
                 `-.....--::::/:
                `.......--::////:
               `...`....---:::://:
             `......``..--:::::///:`
            `---.......--:::::////+/`
            ----------::::::/::///++:
            ----:---:::::///////////:`
            .----::::::////////////:-`
            `----::::::::::/::::::::-
             `.-----:::::::::::::::-
               ...----:::::::::/:-`
                 `.---::/+osss+:`
                   ``.:://///-.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using pll = pair <ll, ll>;

template <class T> using Tree = tree <T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

template <typename T>
T Max(T a, T b) {
    if(a < b) return b;
    return a;
}

template <typename T>
T Min(T a, T b) {
    if(a < b) return a;
    return b;
}

template <typename T>
T Abs(T a) {
    if(a < 0) return -a;
    return a;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void SetIO() {
#ifdef BLAT
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif // BLAT
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

const int MOD = 1e9 + 7;
const int INF = 1e9;
const int N = 2e5;

int v[5 + N];
pair <int, int> vp[5];

int main() {
    SetIO();

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> v[i];
    sort(v + 1, v + n + 1);

    if(n % 3) {
        if(v[n] != 0) cout << "No\n";
        else cout << "Yes\n";
    } else {
        int scount(0);
        bool ok;
        for(int i = 1; i <= n; i++) {
            ok = false;
            for(int j = 1; j <= scount; j++) {
                if(vp[j].first == v[i]) {
                    vp[j].second++;
                    ok = true;
                }
            }

            if(ok == false) {
                vp[++scount] = make_pair(v[i], 1);
            }

            if(scount > 3) {
                cout << "No\n";
                i = n + 1;
            }
        }

        if(scount == 3) {
            if(vp[1].second != n / 3 || vp[2].second != n / 3)
                cout << "No\n";
            else if((vp[1].first ^ vp[2].first ^ vp[3].first) == 0) cout << "Yes\n";
            else cout << "No\n";
        } else if(scount == 2) {
            if(vp[1].first == 0 && vp[1].second == n / 3) cout << "Yes\n";
            else cout << "No\n";
        } else if(scount == 1 && vp[1].first == 0) cout << "Yes\n";
        else if(scount == 1) cout << "No\n";
    }
    return 0;
}
