#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> c(n);
    vector<vector<int>> a(n, vector<int>(m));
    rep(i,n){
        cin >> c[i];
        rep(j,m) cin >> a[i][j];
    }
    int ans = 1e9;
    rep(S,(1<<n)){
        int cost = 0;
        vector<int> score(m, 0);
        rep(i,n){
            if(S>>i & 1){
                cost += c[i];
                rep(j,m){
                    score[j] += a[i][j];
                }
            }
        }
        bool ok = true;
        rep(j,m){
            if(score[j] < x) ok = false;
        }
        if(ok) chmin(ans, cost);
    }
    if(ans == 1e9) ans = -1;
    cout << ans << endl;
    return 0;
}
