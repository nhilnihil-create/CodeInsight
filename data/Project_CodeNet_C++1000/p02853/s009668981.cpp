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

    int x, y;
    cin >> x >> y;
    if (x == 1 && y == 1) {
        cout << 1000 * 1000 << endl;
        exit(0);
    }   

    int ans = 0;
    vector <int> t = {100000, 200000, 300000};
    if (x <= 3)
        ans += t[3 - x];
    if (y <= 3)
        ans += t[3 - y];
    cout << ans << endl;
}