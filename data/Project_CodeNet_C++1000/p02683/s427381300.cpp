#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,x;
    cin >> n >> m >>x;
    vector<vector<int>> a(n,vector<int>(m));
    vector<int> c(n);

    for(int i=0; i<n; i++){
        cin >> c.at(i);
        for(int j=0; j<m; j++) cin >> a.at(i).at(j);
    }

    int ans = 1000000000;
    int all = 1<<n;

    for(int mask =0; mask < all; mask++){
        vector<int> level(m);
        int cost =0;
        for(int i=0; i<n; i++){
            if((mask>>i)&1){
                cost += c.at(i);
                for(int j=0; j<m; j++){
                    level.at(j) += a.at(i).at(j);
                }
            }
        }
        bool ok = true;
        for(int j=0; j<m; j++){
            if(level.at(j) < x) ok = false;
        }
        if(ok) ans = min(ans,cost);
    }
    if(ans == 1000000000) cout << -1 << endl;
    else cout << ans << endl;
    
}