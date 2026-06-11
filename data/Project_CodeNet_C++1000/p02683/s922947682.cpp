#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,m,x;
    cin >> n >> m >> x;
    
    vector<vector<int>> a(n, vector<int>(m));
    vector<int> c(n);
    
    for(int i=0;i<n;i++) {
        cin >> c[i];
        for(int j=0;j<m;j++) cin >> a[i][j];
    }
    long long ans = 12345678;
    int all = 1<<n;
    
    for(int bit=0;bit<all;bit++){
        long long cost = 0;
        vector<int> level(m);
        for(int i=0;i<n;i++){
            if((bit>>i)&1){
                cost+=c[i];
                for(int j=0;j<m;j++){
                    level[j]+=a[i][j];
                }
            }
        }
        bool ok = true;
        for(int j=0;j<m;j++){
            if(level[j] < x) ok = false;
        }
        if(ok)ans=min(ans,cost);
    }
 
    if(ans==12345678)cout << -1;
    else cout << ans;
    
    return 0;
}
