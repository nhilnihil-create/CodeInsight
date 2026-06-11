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

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int n;
    cin >> n;
    if (n == 1 || (n & (n - 1)) == 0) {
        cout << "No";
        return 0;
    }
    cout << "Yes\n";
    for (int i = 2; i < n; i += 2) {
        cout << i << ' ' << i + 1 << '\n';
        cout << i + 1 << ' ' << 1 << '\n';
        cout << 1 << ' ' << n + i << '\n';
        cout << n + i << ' ' << n + i + 1 << '\n';
    }
    cout << n + 3 << ' ' << n + 1 << '\n';
    if (n % 2 == 0) {
        for (int i = 0; i < 17; i++) {
            if (n >> i & 1) {
                cout << n << ' ' << (1 << i) + 1 << '\n';
                cout << n + (n ^ (1 << i)) << ' ' << 2 * n << '\n';
                break;
            }
        }
    }

}
