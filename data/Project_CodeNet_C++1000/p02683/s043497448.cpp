// Hail god Yato
 
#include <bits/stdc++.h> 
using namespace std;
 
#define hs ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
const ll mod = 1000000007;
const ll INF = 1e18;
const ll MAX = 100001;
//
//
ll n, m, x;
void solve(){
    cin>>n>>m>>x;
    vector<vector<int>> vec(n, vector<int>(m+1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= m; j++){
            cin>>vec[i][j];
        }
    }

    ll ans = INF;
    for(int i = 0; i < (1<<n); i++){
        vector<int> temp(m, 0);
        ll price = 0;
        for(int j = 0; j < n; j++){
            if((i>>j)&1){
                price += vec[j][0];
                for(int k = 1; k < m+1; k++)
                    temp[k-1] += vec[j][k];
            }
        }

        int f = 0;
        for(int j = 1; j < m+1; j++){
            if(temp[j-1] < x){
                f = 1;
                break;
            }
        }
        if(!f){
            ans = min(ans, price);
        }
    }
    if(ans == INF)
        cout<<"-1";
    else
        cout<<ans;
}
int main(){ 
        hs;
        ll t;
        t=1;
        // cin>>t;
        for (int i=1; i<=t; i++){
                //cout<<"Case #"<<i<<": ";
                solve();
         }
        return 0; 
}