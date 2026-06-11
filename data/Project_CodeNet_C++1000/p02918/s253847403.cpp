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
const int mod = 1e9+7;

int main() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    s += 'X';
    vector<char> t;
    int ans = 0;
    rep(i,n) {
        if (s[i] == s[i+1]) ans++;
        else t.push_back(s[i]);
    }
    int n_t = t.size();
    if (n_t&1) {
        ans += 2*min(k,n_t/2);
    } else {
        if (k <= n_t/2-1) ans += 2*k;
        else ans += 2*(n_t/2-1)+1;
    }
    cout << ans << endl;
}