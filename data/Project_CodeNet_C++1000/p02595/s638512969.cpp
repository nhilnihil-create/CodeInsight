#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (register int i = a; i <= b; i++)
 

ll n, d, a[200010];
int cnt;
inline void solve(int T) {
    cin >> n >> d;
    cnt = 0;
    ll x, y;
    rep(i, 1, n) {
         cin >> x >> y;
         if(x * x + y * y <=d * d)cnt++;
    }
    cout << cnt << endl;

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