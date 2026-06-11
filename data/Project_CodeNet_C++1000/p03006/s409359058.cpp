#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int n;
    cin >> n;
    vector <ii> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i].f >> a[i].s;

    vector <ii> v;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            v.app(mp(a[j].f - a[i].f, a[j].s - a[i].s));
        }   
    }   

    if (n == 1) {
        cout << 1 << endl;
        exit(0);
    }   

    int ans = 1e9;
    for (auto e : v) {
        if (e.f == 0 && e.s == 0)
            continue;

        int cnt = 0;

        for (auto p : a) {
            auto w = mp(p.f + e.f, p.s + e.s);
            for (auto pp : a) {
                if (pp == w) {
                    ++cnt;
                    break;
                }   
            }   
        }   

        ans = min(ans, n - cnt);
    }
    cout << max(ans,1ll) << endl;

}