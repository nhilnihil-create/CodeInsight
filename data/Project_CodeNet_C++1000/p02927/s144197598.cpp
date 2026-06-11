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

    int M, D;
    cin >> M >> D;

    int ans = 0;
    for (int m = 1; m <= M; ++m) {
        for (int d = 1; d <= D; ++d) {
            string s = to_string(d);
            if (s.size() == 2) {
                int d1 = s[1] - '0';
                int d10 = s[0] - '0';
                if (d1 >= 2 && d10 >= 2 && d1 * d10 == m)
                    ++ans;
            }   
        }   
    }   
    cout << ans << endl;

}