#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define P pair<ll, ll>
using ll = long long;
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl
#define coel cout << endl
#define pb push_back
#define sz(v) ((ll)(v).size())
using namespace std;  
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define pp pair<ll, pair<ll, ll>> 

////////////////////////////////////////////////////////


int main() {
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    ll cnt = 0;
    ll rl = 0;
    rep(i, 0, sz(s)-1){
        if(s[i] == 'R' && s[i+1] == 'R') cnt++;
        if(s[i] == 'L' && s[i+1] == 'L') cnt++;
        if(s[i] == 'R' && s[i+1] == 'L') rl++;
    }
    cnt += 2*k;
    if(cnt > n-1) cnt = n-1;
    co(cnt);

    return 0;
}
