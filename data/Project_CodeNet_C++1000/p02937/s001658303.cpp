#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    string S;
    cin >> S;
    string T;
    cin >> T;
    ll len = S.size();
    vector<vector<ll> > vec(26, vector<ll>(0));
    rep(i,len){
        int x = S[i] - 'a';
        ll y = i + 1;
        vec[x].push_back(y);
    }
    rep(i,len){
        int x = S[i] - 'a';
        ll y = i + len + 1;
        vec[x].push_back(y);
    }
    ll now = 0;
    ll ans = 0;
    rep(i,T.size()){
        int x = T[i] - 'a';
        if (vec[x].size() == 0){
            ans += -500000000000;
        }
        else{
            vector<ll>::iterator itr = upper_bound(all(vec[x]), now);
            ans += (*itr - now);
            if (*itr > len) now = *itr - len;
            else now = *itr;
        }
    }
    if (ans < 0) cout << -1 << endl;
    else cout << ans << endl;
}