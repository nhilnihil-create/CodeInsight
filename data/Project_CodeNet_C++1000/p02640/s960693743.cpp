#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (register int i = a; i <= b; i++)

int x, y;

inline void solve(int T) {
    cin >> x >> y;
    rep(i, 0, x) {
        if(i * 2 + (x - i) * 4 == y) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";

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