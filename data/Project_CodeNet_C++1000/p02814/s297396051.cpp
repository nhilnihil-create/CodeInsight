#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define lc 2 * v
#define rc 2 * v + 1
#define mid (s + e) / 2
#define ll long long
#define int long long
#define ld long double
#define pii pair <int , int>
#define pll pair <long long , long long>
#define FAST ios::sync_with_stdio(false);cin.tie(0);
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

const int maxn = 1e5 + 100 , N = 1e5 + 5 , SQ = 600 , base = 1999 , mod = 1e9 + 7 , INF = 1e18 , lg = 17;

int n , m , a[maxn] , can[maxn] , b[maxn];
int mini = INF , idx , T;

inline int gcd(int a , int b) {
   if (b == 0)
       return a;

   return gcd(b , a % b);
}

inline int lcm(int a , int b) {
    return a / gcd(a , b) * b;
}

int32_t main() {
    FAST
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] /= 2;
    }
    sort (a , a + n);
    int mini = a[0] , cnt = 0;
    while((mini & 1) == 0) {
        mini /= 2;
        cnt++;
    }
    T = a[0];
    for (int i = 1; i < n; ++i) {
        T = lcm(T , a[i]);
    }
    int Q = T , c1 = 0;
    while((Q & 1) == 0) {
        Q /= 2;
        c1++;
    }
    if(c1 > cnt) {
        cout << 0 << '\n';
        return 0;
    }
    int ans = m / T;
    if(ans & 1) {
        cout << (ans + 1) / 2 << '\n';
    }
    else {
        cout << (ans / 2) << '\n';
    }
 }
