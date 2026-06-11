#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> g(n,vector<int>(n,-1));
    for(int i=0; i<n; i++){
        int a; cin >> a;
        for(int j=0; j<a; j++){
            int x,y; cin >> x >> y;
            g[i][x-1] = y;
        }
    }
    int ans = 0;
    for(int bit=0; bit<(1<<n); bit++){
        int cnt = 0;
        bool ok = true;
        for(int i=0; i<n; i++){
            if(bit & (1<<i)){
                for(int j=0; j<n; j++){
                    if(g[i][j] == 0 && (bit & (1<<j))) ok = false;
                    if(g[i][j] == 1 && !(bit & (1<<j))) ok = false;
                    if(!ok) break;
                }
                cnt++;                
            }
            if(!ok) break;
        }
        if(ok) ans = max(ans,cnt);
    }
    cout << ans << endl;
}