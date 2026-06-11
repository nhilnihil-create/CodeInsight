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
    ll n, m ,k;
    cin>>n>>m>>k;
    vector<ll> fst(n), snd(m);
    for(int i = 0; i < n; i++)
        cin>>fst[i];
    for(int i = 0; i < m; i++)
        cin>>snd[i];
    ll ans = -1, f = 0, s = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        if(cnt + fst[i]> k)
            break;
        ++f;
        cnt += fst[i];
    }
    for(int i = 0; i < m; i++){
        if(cnt + snd[i]> k)
            break;
        ++s;
        cnt += snd[i];
    }
    // cout<<s;
    ans = max(ans, f+s);
    for(int i = f-1; i>=0 ; i--){
        cnt -= fst[i];
        while(s < m && cnt+snd[s] <= k){
            cnt += snd[s];
            ++s;
            ans = max(i+s, ans);
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