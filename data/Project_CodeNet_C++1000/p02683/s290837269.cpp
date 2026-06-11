#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 12345678;
int main(){
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> c(n);
    vector<vector<int>> a(n, vector<int>(m));
    int ans = INF;
    rep(i,n){
        cin >> c[i];
        rep(j,m) cin >> a[i][j];
    }
    rep(is, 1 << n){
        // cout << bitset<3>(is) << " ";
        int sum = 0;
        vector<int> skill(n);
        bool can = false;
        int cnt = 0;
        rep(i,n){
            if(is >> i & 1){
                sum += c[i];
                rep(j,m){
                    skill[j] += a[i][j];
                    // cout << skill[j] << " ";
                }
            }
        }
        rep(i,m){
            if(skill[i] >= x){
                cnt++;
            }
        }
        // cout << sum << endl;
        // if(is == 0) ans = sum;
        if(cnt == m && ans > sum) ans = sum;
    }
    // rep(i,m) cin >> a[0][i];
    // rep(i,m) cout << a[0][i] << endl;
    // rep(i,n){
    //     cout << c[i] << " ";
    //     rep(j,m) cout << a[i][j] << " ";
    //     cout << endl;
    // }
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}