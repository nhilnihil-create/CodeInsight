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
                void solve(){
                    ll n;
                    cin>>n;
                    // vector<vector<int>> tree(n+1);
                    vector<pair<int, int>> edges;
                    for(int i = 0; i < n-1; i++){
                        ll f, s;
                        cin>>f>>s;
                        edges.push_back({min(f, s), max(f, s)});
                        // tree[f].push_back(s);
                        // tree[s].push_back(f);
                    }

                    ll ans = 0;
                    for(int i = 0; i < n-1; i++){
                        ans -= (n-edges[i].second+1)*(edges[i].first);
                    }
                    // cout<<ans;
                    for(int i = 1; i <= n; i++)
                        ans += i*(n-i+1);
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
 
 