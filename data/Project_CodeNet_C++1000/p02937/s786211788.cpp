#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) rep(i,x.size()) cout << x[i] << " "
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1e5;

int main() {
    string s, t; cin >> s >> t;
    int n_s = s.size();
    int n_t = t.size();
    queue<char> q;
    rep(i,n_t) q.push(t[i]);
    vvint data(26);
    rep(i,2*n_s) {
        data[s[i%n_s]-'a'].push_back(i);
    }
    rep(i,n_t) {
        if (data[t[i]-'a'].size() == 0) {cout << -1 << endl; return 0;}
    }
    ll ans = 0;
    int now = -1;
    while (!q.empty()) {
        now = *lower_bound(all(data[q.front()-'a']),now+1);
        if (now >= n_s) {
            ans += n_s; 
            now %= n_s;
        }
        q.pop();
    }
    cout << ans + now + 1 << endl;
}