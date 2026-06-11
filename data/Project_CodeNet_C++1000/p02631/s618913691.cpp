#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(void){
    int n;
    cin>>n;
    vector<ll> v(n);
    rep(i, n){
        cin>>v[i];
    }
    vector<vector<int> > table(n, vector<int>(30));
    rep(i, n){
        ll x = v[i];
        rep(j, 30){
            table[i][j] = x%2;
            x = (x-x%2)/2;
        }
    }
    rep(i, 30){
        bool change = false;
        int now = 0;
        for(int j = 1;j<=n-1;j++){
            now += table[j][i];
        }
        if(now%2 != table[0][i]){
            rep(j, n){
                if(table[j][i] == 1) table[j][i] = 0;
                else table[j][i] = 1;
            }
        }
    }
    rep(i, n){
        ll beki = 1;
        ll ans = 0;
        rep(j, 30){
            ans += beki*(ll)table[i][j];
            beki *= 2;
        }
        cout<<ans<<endl;
    }
    return 0;
}