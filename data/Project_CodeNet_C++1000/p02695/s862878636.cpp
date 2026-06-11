// Hail god Yato
 
#include <bits/stdc++.h> 
using namespace std;
 
#define hs ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
const ll mod = 1000000007;
const ll INF = 1e18;
const ll MAX = 52;
//
//
int n, m, q;
// vector<int> query[MAX];
ll ans;
void check(int idx, int val, vector<int>& temp, vector<vector<int>>& query){
    if(val > m)
        return ;
    if(idx == n+1){
        // return ;
        ll t = 0;
        // for(int i = 1; i <= n; i++)
        //     cout<<temp[i]<<" ";
        // cout<<"\n";
        for(auto itr : query)
            t += ((temp[itr[1]] - temp[itr[0]] == itr[2])? itr[3] : 0);
        ans = max(ans, t);
        // cout<<t<<"\n";
        return ;
    }
    for(int i = val; i <= m; i++){
        temp[idx] = i;
        check(idx+1, i, temp, query);
    }
}
void solve(){
    cin>>n>>m>>q;
    ans = 0;
    vector<vector<int>> query(q, vector<int>(4));
    for(int i = 0; i < q; i++){
        for(int j = 0; j < 4; j++)
            cin>>query[i][j];
    }

    // for(auto itr : query)
    //     cout<<itr[0]<<"\n";
    vector<int> temp(n+10);
    check(1, 1, temp, query);
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