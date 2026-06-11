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
    vector <int> d(n+1), cnt(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
        ++cnt[d[i]]; 
    }   
    
    int ans = 1;
    const int MOD = 998244353;

    if (cnt[0] != 1) {
        cout << 0 << endl;
        exit(0);
    }   
    if (d[1] != 0) {
        cout << 0 << endl;
        exit(0);
    }   

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < cnt[i]; ++j)
            ans = ans * cnt[i-1] % MOD;
    }   
    cout << ans << endl;
}