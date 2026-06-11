#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    int n,m,x;
    cin >>n>>m>>x;
    vector<int> c(n);
    vector<vector<int>> a(n, vector<int>(m));
    rep(i, n){
        cin >> c[i];
        rep(j, m){
            cin >> a[i][j];
        }
    }

    int ans=12345678;
    rep(tmp, (1<<n)){
        vector<int> level(m);
        int cnt=0;
        rep(i, n){
            if((tmp>>i)&1){
                cnt += c[i];
                rep(j, m){
                    level[j] += a[i][j];
                }
            }
        }
        bool ok = true;
        rep(j, m){
            if(level[j]<x)
                ok=false;
        }
        if(ok) ans = min(ans,cnt);
    }
    if(ans==12345678) cout << -1 << endl;
    else cout << ans << endl;
}