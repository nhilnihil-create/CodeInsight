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
    vector<ll> vec(n);
    set<ll> s;
    for(int i = 0; i < n; i++){
        cin>>vec[i];
        // s.insert(vec[i]);
    }
    // n = s.size();
    // // cout<<n;
    // vec.clear();
    // for(ll k : s)
    //     vec.push_back(k);

    ll ans = 0;
    for(int i = 0; i <n ; i++)
        for(int j = i+1; j < n; j++)
            for(int k = j+1; k < n; k++){
                ll sm = vec[i]+vec[j]+vec[k];
                if(vec[i]!=vec[j] && vec[i]!=vec[k] && vec[j]!=vec[k] && 2*vec[i] < sm &&  2*vec[j] < sm && 2*vec[k] < sm )
                    ++ans;
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