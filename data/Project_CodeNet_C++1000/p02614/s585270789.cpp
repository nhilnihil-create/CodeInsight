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
                vector<string> store;
                int n, m;
                int check(int x, int y, int k){
                    int cnt = 0;
                    // cout<<x<<" ";
                    for(int i= 0 ; i < n; i++)
                        for(int j = 0; j < m; j++)
                            if(store[i][j] == '#' && (x&(1<<i))==0 && (y&(1<<j))==0){
                                ++cnt;
                            }

                    return cnt==k;
                }
                void solve(){
                    int k;
                    cin>>n>>m>>k;
                    store.resize(n, "");
                    for(int i = 0; i < n; i++)
                        cin>>store[i];
                    int ans = 0;
                    for(int i = 0; i < (1<<n); i++){
                        for(int j = 0; j < (1<<m); j++)
                            if(check(i, j, k)){
                                ++ans;
                            }
                    }
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
 
