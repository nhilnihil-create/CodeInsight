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
    int n, k, s;
    cin >> n >> k >> s;

    const int INF = 1000 * 1000 * 1000;

    if (s == INF) {
    for (int i = 0; i < k; ++i)
        cout << s << ' ';
    for (int i = 0; i < n - k; ++i)
        cout << INF -1 << ' ';
    cout << endl;
    exit(0);
    }   

    for (int i = 0; i < k; ++i)
        cout << s << ' ';
    for (int i = 0; i < n - k; ++i)
        cout << s + 1 << ' ';
    cout << endl;

}