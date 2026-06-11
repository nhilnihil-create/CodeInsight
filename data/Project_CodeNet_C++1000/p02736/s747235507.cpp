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
uniform_int_distribution <int> range(1, 3);
typedef pair <int, int> pii;

const int N = 1000007;
int n, a[N], b[N], cnt[4];

int f(int x) {
    int tmp = 2, res = 0;
    while (x >= tmp) {
        res += x / tmp;
        tmp *= 2;
    }
    return res;
}

int c(int x, int y) {
    if (y > x) {
        return 0;
    }
    if (f(x) > f(y) + f(x - y)) {
        return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    cin >> n;
    char ch;
    for (int i = 1; i <= n; i++) {
        cin >> ch;
        a[i] = (ch - '0');
        a[i]--;
        cnt[a[i]]++;
    }
    if (cnt[1]) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 2) {
                a[i] = 0;
            }
            ans ^= (a[i] & c(n - 1, i - 1));
        }
        cout << ans;
    }   else {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 2) {
                a[i] = 1;
            }
            ans ^= (a[i] & c(n - 1, i - 1));
        }
        if (ans) {
            cout << 2;
        }   else {
            cout << 0;
        }
    }
}
