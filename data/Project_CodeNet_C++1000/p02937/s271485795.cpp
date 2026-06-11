#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1'000'000'007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)
#define repd(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=a-1; (ll)(b)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define rALL(x) x.rbegin(), x.rend()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<vector<char>> g;
int main(){
    string s, t;   cin >> s >> t;
    vector<vector<ll>> key(26);
    ll n=s.size();
    rep(i, n){
        key[s[i]-'a'].push_back(i+1);
    }
    ll res=0;
    rep(i, t.size()){
        if(!key[t[i]-'a'].size()) res = -1;
    }
    
    if(0<=res){
        ll now=0;
        rep(i, t.size()){
            ll c = t[i]-'a';
            auto itr = upper_bound(ALL(key[c]), now);
            if(itr==key[c].end()){
                res += s.size()-now + *key[c].begin();
                now = *key[c].begin();
            }else{
                res += *itr-now;
                now = *itr;
            }
        }
    }
    cout << res << endl;
}
