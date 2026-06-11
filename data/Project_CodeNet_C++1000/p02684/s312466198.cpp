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
    ll n, k;
    cin>>n>>k;
    vector<int> vec(n+1);
    for(int i = 1; i <= n; i++)
        cin>>vec[i];

    int idx = 1;
    int cycle_len = 0, pre_cycle = 0;
    vector<int> vis(n+1, -1);
    vis[1] = 0;
    while(true){
        idx = vec[idx];
        if(vis[idx] != -1){
            pre_cycle = vis[idx];
            cycle_len -= pre_cycle;
            ++cycle_len;
            break;
        }
        ++cycle_len;
        vis[idx] = cycle_len;
    }
    // cout<<cycle_len;
    // for(int i = 0; i <= n; i++)
    //     cout<<vis[i]<<" ";
        
    if(pre_cycle >= k)
        idx = 1;
    else{
        k -= pre_cycle;
        k = k%cycle_len;
    }

    while(k--)
        idx = vec[idx];
    cout<<idx;
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