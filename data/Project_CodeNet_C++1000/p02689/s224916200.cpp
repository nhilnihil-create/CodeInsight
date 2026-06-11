#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    vector<vector<int>> a(n);
    vector<int> count(n);
    rep(i,m){
        int A, B; cin >> A >> B;
        a[A-1].push_back(B-1);
        count[A-1] ++;
        a[B-1].push_back(A-1);
        count[B-1] ++;
    }
    int ans = 0;
    // rep(i,n) cout << count[i] << " " ;
    // cout << endl;
    rep(i,n){
        bool can = true;
        // if(count[i] == 0){
        //     ans++;
        //     continue;
        // }
        rep(j,count[i]){
            if(h[i] <= h[a[i][j]]) can = false;
        }
        if(can) ans++;
        // cout << ans << " ";
    }
    // cout << endl;
    cout << ans << endl;
    return 0;
}