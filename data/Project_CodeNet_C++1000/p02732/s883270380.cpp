#include<bits/stdc++.h>
#define int long long
/* #define double long double */
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
#define MOD 1000000007
using namespace std;
using ll = long long;
typedef vector<int> vi;
typedef pair<int, int> P;
#define rrep(i,a,b) for(int i=a;i>=b;i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }



signed main(){
    ll n;
    cin >> n;
    vi cnt(n), a(n);

    rep(i, n){
        ll tmp;
        cin >> tmp;
        --tmp;
        a[i] = tmp;
        cnt[tmp]++;
    }

    /* rep(i, n) cout << a[i] << " ";
    cout << endl;
 */
    ll ans = 0;
    rep(i, n){
        int num = cnt[i];
        ans += num*(num-1)/2;
    }

    rep(i, n){
        ll sub = cnt[a[i]] - 1;
        cout << ans - sub << endl;
    }
}