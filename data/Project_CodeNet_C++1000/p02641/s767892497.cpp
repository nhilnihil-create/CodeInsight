#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (register int i = a; i <= b; i++)

int n, x;
int p[110], cnt[110];

inline void solve(int T) {
    cin >> x >> n;
    memset(cnt, 0, sizeof(cnt));
    rep(i, 1, n) cin >> p[i], cnt[p[i]] = 1;
    for(int i = 0; x - i >= 0 && x + i <= 101; i++) {
        if(x - i >= 0 && !cnt[x - i]) {
            cout << x - i << endl;
            return;
        }
        if(x - i <= 101 && !cnt[x + i]) {
            cout << x + i << endl;
            return;
        }
    }

}   
int main()
{
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
 
    // freopen("in.txt", "r", stdin);
    // freopen("out2.txt", "w", stdout);
 
    int T = 1;
    // cin >> T;
    rep(i, 1, T) solve(i);
}