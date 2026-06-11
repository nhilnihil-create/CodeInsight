#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int main(){
    int n;
    cin >> n;
    VL a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];
    sort(all(a));
    sort(all(b));
    if (n % 2 == 1){
        int ni = n / 2;
        ll mx = b[ni];
        ll mn = a[ni];
        ll ans = (mx - mn) + 1;
        cout << ans << endl;
    }else{
        int nileft = (n-1) / 2, niright = n / 2;
        ll mx = (b[nileft] + b[niright]) / 2;
        ll mn = ceil((a[nileft] + a[niright]) / 2.0);
        ll ans = (mx - mn) + 1;
        ans += mx - mn;
        if ((b[nileft] + b[niright]) % 2 == 1) ans++;
        if ((a[nileft] + a[niright]) % 2 == 1) ans++;
        cout << ans << endl;
    }
    return 0;
}