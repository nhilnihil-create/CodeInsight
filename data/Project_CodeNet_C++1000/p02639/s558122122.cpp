#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (register int i = a; i <= b; i++)


inline void solve(int T) {
    int a[10], cnt[10];
    rep(i, 1, 5) cnt[i] = 0;
    rep(i, 1, 5) cin >> a[i], cnt[a[i]] = 1;
    rep(i, 1, 5) if(cnt[i] == 0) {
        cout << i << endl;
        return;
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