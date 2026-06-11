// Hail god Yato
 
#include <bits/stdc++.h> 
using namespace std;
 
#define hs ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
const ll mod = 1000000007;
const ll INF = 1e18;
const ll MAX = 1000005;
//
//
                void solve(){
                    ll n;
                    cin>>n;
                    vector<int> vec(n);
                    vector<int> cnt(MAX, 0);
                    for(int i = 0; i < n; i++)
                        cin>>vec[i];
                    sort(vec.begin(), vec.end());
                    ll ans = 0;
                    for(int i = 0; i < n; i++){
                        if(cnt[vec[i]] != 0){
                            cnt[vec[i]] = 2;
                            continue;
                        }
                        cnt[vec[i]] = 1;
                        for(int j = vec[i]*2; j < MAX; j += vec[i])
                            cnt[j] = 2;
                    }
                    for(int i : vec)
                        ans += cnt[i] == 1;
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