#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
typedef long long int lli;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

ll mod = 1000000007;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll ans = 0;
    rep(i, 60){
        ll one = 0, zero = 0;
        rep(j,n){
            if ( (a[j]>>i) & 1) one++;
            else zero++;
        }
        ll now = one * zero % mod;
        rep(j, i) now = 2 * now % mod;
        ans += now;
        ans %= mod;
    }
    cout << ans << endl;
}