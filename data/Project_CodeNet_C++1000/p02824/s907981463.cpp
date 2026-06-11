#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 1e5 + 7;
int n, m, v, p, a[N];
bool check(int mid) {
    if (mid >= n - p)
        return 1;
    vector <int> t;
    for (int i = 0; i <= n - p; ++i)
        if (i != mid)
            t.app(a[i]);
    int add = max(0ll, v - p);            
    int sum = 0;
    for (int e : t)
        if (a[mid] + m < e)
            return 0;
    for (int e : t)
        sum += min(m, a[mid] + m - e);
    return sum >= add * m;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m >> v >> p;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    int l = -1;
    int r = n - p;
    while (l < r - 1) {
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }   
    cout << n - r << '\n';
}   