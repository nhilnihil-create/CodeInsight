#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (ll i = 0; i < (n); i++)
typedef pair<ll,ll> P;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}


int main(){

    string s,t;
    cin >> s >> t;
    vector<vector<ll>> c(26);
    rep(i,s.size()){
        ll id = s[i] - 'a';
        c[id].push_back(i);
    }
    
    ll ans = 0;
    ll p = -1; // sの何文字目か
    rep(i,t.size()){
        ll id = t[i] - 'a';

        if(c[id].size()==0){
            cout << -1 << endl;
            return 0;
        }

        auto it = upper_bound(c[id].begin(), c[id].end(), p);
        if(it != c[id].end()){
            p = *it;
        }else{
            p = c[id][0];
            ans++;
        }
        // cout << p << endl;

    }

    cout << ans*s.size() + p+1 << endl;


    return 0;
}