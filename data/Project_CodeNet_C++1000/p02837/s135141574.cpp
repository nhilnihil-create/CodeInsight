#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n;
    cin >> n;
    vector<vector<int>> g(n,vector<int>(n,-1));
    rep(i,n){
        int m;
        cin >> m;
        rep(j,m){
            int x,y;
            cin >> x >> y;
            --x;
            g[i][x] = y; //i banme no hito no x ni taisuru syougen
        }
    }

    int ans = 0;
    rep(i,1<<n){
        vector<int> d(n);
        rep(j,n) if(i>>j &1) d[j]=1;
        bool check = true;
        rep(j,n){
            if(d[j]){
                rep(k,n){
                    if(g[j][k] == -1) continue; //syougenn nasi
                    if(g[j][k] != d[k]) check = false;
                }
            }
        }
        if (check) ans = max(ans,__builtin_popcount(i));
    }
    cout << ans << endl;
    return 0;
}