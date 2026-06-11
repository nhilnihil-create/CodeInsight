#include <bits/stdc++.h>
using namespace std;
int main() {

    int n, m, x;
    cin >> n >> m >> x;
    int ans = 10000000;
    int v[n][m+1];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m+1;j++){
            cin >> v[i][j];
        }
    }

    for(int i=0;i<(1<<n);i++) {
        int p = 0;
        int tmp[m];
        for(int i=0;i<m;i++) tmp[i]=0;

        for(int j=0;j<n;j++){
            if((i>>j)&1) {
                p += v[j][0];
                for(int k=0;k<m;k++){
                    tmp[k] += v[j][k+1]; 
                    //cout << i<<" "<<v[j][k+1] << endl;
                }

            }
        }
        for(int k=0;k<m;k++) {
            if(tmp[k]<x) break;
            if(k==m-1) ans = min(ans, p);
        }
        
    }
    if(ans==10000000) cout << -1 << endl;
    else cout << ans << endl;
}