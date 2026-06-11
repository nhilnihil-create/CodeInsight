#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e9;
const ll INF = 1e18;
const ld EPS = 1e-10;

int main(){
    string s, t;
    cin >> s >> t;
    vector<ll> ids[26];
    ll n = s.size();
    rep(i, n){
        int j = s[i]-'a';
        ids[j].pb(i);
    }
    //[0,now)
    ll now = 0;
    rep(i, t.size()){
        int j = t[i]-'a';
        ll k = now%n;
        if(ids[j].empty()) {cout << -1 << endl; return 0;}
        int a = lower_bound(all(ids[j]), k) - ids[j].begin();
        if(a == ids[j].size()) now += n+ids[j][0]-k;
        else now += ids[j][a]-k;
        now++;
    }
    cout << now << endl;
}