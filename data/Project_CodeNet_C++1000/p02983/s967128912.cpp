#include<bits/stdc++.h>
/* #define int long long */
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
    ll l, r;
    cin >> l >> r;
    ll ans = 2019;
    if(r - l >= 2019){
        cout << 0 << endl;
        return 0;
    }
    for(ll i = l+1; i <= r; i++){
        for(ll j = l; j < i; j++){
            chmin(ans, ((i*j)%2019));
            if(ans == 0) break;
        }
    }
    cout << ans << endl;
}