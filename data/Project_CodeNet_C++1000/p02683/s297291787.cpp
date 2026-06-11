#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int inf = 1000000000;

int main(){
    int n,m,x;
    cin >> n >> m >> x;
    vector<int> c(n);
    int a[n][m];
    rep(i,n){
        cin >> c[i];
        rep(j,m){
            cin >> a[i][j];
        }
    }
    int ans = inf;
    for(int i=0; i<(1<<n); i++){
        ll tot = 0;
        ll b[m];
        rep(k,m) b[k] = 0;
        for(int j=0; j<n; j++){
            if(i & (1<<j)){
                rep(k,m){
                    b[k]+=a[j][k];
                }
                tot += c[j];
            }
        }
        rep(k,m){
            if(b[k]<x) break;
            if(k==m-1){
                ans = min(ll(ans),tot);
                //cout << i << " " << tot << endl;
            }
        }
    }
    if(ans == inf){
        cout << -1 << endl;
    }
    else{
        cout << ans << endl;
    }
}