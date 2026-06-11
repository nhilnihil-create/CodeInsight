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


signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 1;
    int open = 0;
    for (int i = 0; i < 2 * n; ++i) {
        if (open < 0) {
            cout << 0 << endl;
            exit(0);
        }   

        bool w = s[i] == 'B';
        if ((open&1) == w) {
            ans = mod(ans * open);
            --open;
        }   
        else {
            ++open;
        }

        if (open < 0) {
            cout << 0 << endl;
            exit(0);
        }   

    }   

    //cout << "tak " << ' ' << open << endl;

    if (open) {
        cout << 0 << endl;
        exit(0);
    }   

    for (int i = 1; i <= n; ++i)
        ans = mod(ans * i);
    cout << ans << endl;
}