#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> s(n,vector<int>(n,-1));
    rep(i,n) {
        s[i][i] = 1;
        int a;
        cin >> a;
        rep(j,a) {
            int x, y;
            cin >> x >> y;
            x--;
            s[i][x] = y;
        }
    }
    
    int ans = 0;
    rep(i,1<<n) {
        vector<int> check(n,-1);
        int sum = 0;
        bool tf = true;
        
        rep(j,n) {
            if(i>>j & 1)
                check[j] = 1;
            else
                check[j] = 0;
        }
        
        rep(j,n) {
            if(check[j]) {
                sum++;
                rep(k,n) {
                    if(s[j][k] == -1) {
                        continue;
                    }
                    else {
                        if(check[k] != s[j][k]) {
                            //cout << j << " " << k << endl;
                            tf = false;
                            break;
                        }
                    }
                }
            }
            
            if(!tf)
                break;
        }
        if(tf) {
            //cout << i << endl;
            ans = max(ans, sum);
        }
    }
    
    cout << ans << endl;
    
    
    
    return 0;
}
