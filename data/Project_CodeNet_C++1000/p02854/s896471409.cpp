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
    vector <int> pref(n + 1), post(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        post[i] = post[i + 1] + a[i];
    }   

    int ans = 5e18;
    for (int i = 1; i < n; ++i) {
        int l = pref[i];
        int r = post[i];
        ans = min(ans, abs(r-l));
    }   
    cout << ans << endl;
}