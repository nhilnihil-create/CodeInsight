#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (register int i = a; i <= b; i++)

ll k;

ll ksm(ll a, ll b) {
    ll res = 0;
    for(; b; b <<= 1, a = a * a % k) if(b & 1) res = res * a % k;
    return res;
}

inline void solve(int T) {

    cin >> k;
    ll tmp = 0;
    rep(i, 1, k) {
        tmp = (tmp * 10 + 7) % k;
        if(tmp == 0) {
            cout << i << endl;
            return;
        }
    }
    cout << "-1\n";

}   
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
 
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
 
    int T = 1;
    // cin >> T;
    rep(i, 1, T) solve(i);
    // system("pause");
}