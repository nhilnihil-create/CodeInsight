#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll INF = 1000000009;
ll MOD = 1000000007;


void solve(){

    string s,t;
    cin >> s >> t;
    ll ans = INF;
    for(ll i=0; i<=s.size()-t.size(); i++){
        ll tmp = 0;
        for(ll j=0; j<t.size(); j++){
            if(s[i+j]!=t[j]) tmp++;
        }
        ans=min(ans,tmp);
    }
    cout << ans << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
