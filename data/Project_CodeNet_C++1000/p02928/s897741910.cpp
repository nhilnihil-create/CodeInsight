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

const int MOD = 1000 * 1000 * 1000 + 7;
int mod(int n) {
    n %= MOD;
    if (n < 0) return n + MOD;
    else return n;
}   
int fp(int a, int p) {
    int ans = 1, c = a;
    for (int i = 0; (1ll << i) <= p; ++i) {
        if ((p >> i) & 1) ans = mod(ans * c);
        c = mod(c * c);
    }   
    return ans;
}   
int dv(int a, int b) { return mod(a * fp(b, MOD - 2)); }


int sum(int n) {
    return dv(mod(n * (n + 1)), 2);
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int inv = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            inv += a[i] > a[j];

    int ans = mod(inv * k);
    for (int i = 0; i < n; ++i) {
        int ls = 0;
        for (int j = 0; j < n; ++j)
            ls += a[j] < a[i];
        ans += sum(k - 1) * ls;                    
        ans = mod(ans);
    }   
    cout << ans << endl;
}