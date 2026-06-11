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
    for (int i = 0; i < n; ++i) {
        int x, len;
        cin >> x >> len;
        a[i] = mp(x - len, x + len);
    }   
    auto comp = [](ii a, ii b) {
        return a.s < b.s;
    };   
    sort(all(a), comp);

    int r = -1e18;
    int ans = 0;
    for (auto e : a) {
        if (r <= e.f) {
            r = e.s;
            ++ans;
        }   
    }   
    cout << ans << endl;
}