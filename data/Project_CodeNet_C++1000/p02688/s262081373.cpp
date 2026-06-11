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
    int n, k;
    cin >> n >> k;
    vector<bool> have_snack(n);
    rep(i, k){
        int d;
        cin >> d;
        rep(i, d){
            int a;
            cin >> a;
            --a;
            have_snack[a] = true;
        }
    }

    int ans = 0;
    rep(i, n){
        if(!have_snack[i]) ans++;
    }
    cout << ans << endl;
}