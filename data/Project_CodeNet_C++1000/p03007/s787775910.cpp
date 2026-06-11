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
    vector <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(all(a));
    
    vector <ii> ans;
    for (int i = 1; i < n - 1; ++i) {
        if (a[i] >= 0) {
            ans.app(mp(a[0], a[i]));
            a[0] -= a[i];
        }
    }   
    ans.app(mp(a.back(), a[0]));
    a.back() -= a[0];
    for (int i = 1; i < n - 1; ++i) {
        if (a[i] < 0) {
            ans.app(mp(a.back(), a[i]));
            a.back() -= a[i];
        }   
    }   
    
    cout << ans.back().f - ans.back().s << endl;
    for (auto e : ans)
        cout << e.f << ' ' << e.s << endl;
}