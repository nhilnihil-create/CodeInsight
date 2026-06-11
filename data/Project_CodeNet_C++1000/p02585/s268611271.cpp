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
    vector<ll> perm(n+1), value(n+1);
    for(int i = 1; i <= n; i++)
        cin>>perm[i];
    for(int i = 1; i <= n; i++)
        cin>>value[i];
    ll ans = LONG_LONG_MIN;

    for(int i = 1; i <= n ; i++){
        ll cycle_len = 0;
        ll cycle_val = 0;
        ll vertex = i;
        while(true){
            cycle_val += value[vertex];
            cycle_len++;
            vertex = perm[vertex];
            if(vertex == i)
                break;
        }

        ll fst_cnt = 0;
        ll fst_len = 0;
        vertex = i;
        while(true){    // going from front
            fst_cnt += value[vertex];
            fst_len++;
            if(fst_len > k)
                break;
            ans = max(ans, fst_cnt + max(0ll, cycle_val)*((k-fst_len)/cycle_len));
            vertex = perm[vertex];
            if(vertex == i)
                break;
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