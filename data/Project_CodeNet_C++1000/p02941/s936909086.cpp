//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define db long double
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(), (x).end()

void dout() { cerr << '\n'; }

template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
    cerr << " " << H;
    dout(T...);
}

#ifdef LOCAL
    #define dbg(...) cerr << #__VA_ARGS__, dout(__VA_ARGS__)
#else
    #define dbg(...) ;
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair <int, int> pii;

const int N = 2e5 + 123;
int n, a[N], b[N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    set <pii> st;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        st.insert({b[i], i});
    }
    b[0] = b[n], b[n + 1] = b[1];
    ll ans = 0;
    while (!st.empty()) {
        pii v = *(--st.end());
        st.erase(--st.end());
        int val = v.fi, ind = v.se;
        if (val > a[ind]) {
            if (val <= b[ind - 1] + b[ind + 1]) {
                cout << -1;
                return 0;
            }
            int dif = val - a[ind];
            if (dif % (b[ind - 1] + b[ind + 1]) == 0) {
                ans += dif / (b[ind - 1] + b[ind + 1]);
                val = a[ind];
            }   else {
                ans += val / (b[ind - 1] + b[ind + 1]);
                val %= b[ind - 1] + b[ind + 1];
                st.insert({val, ind});
            }
            if (val < a[ind]) {
                cout << -1;
                return 0;
            }
            b[ind] = val;
            if (ind == n) {
                b[0] = val;
            }
            if (ind == 1) {
                b[n + 1] = val;
            }
        }
    }
    cout << ans;
}
