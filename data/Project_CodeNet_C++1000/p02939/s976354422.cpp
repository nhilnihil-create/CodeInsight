#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define debug(var) do{cout << #var << " : "; view(var);}while(0)
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
template<class T> void view(T e) {cout << e << endl;}
template<class T> void view(const vector<T> &v) {for(const auto &e : v){cout << e << " ";} cout << endl;}
template<class T> void view(const vector<vector<T>> &vv) {for(const auto &v : vv){view(v);}}
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1e5;

int dp[200005][3];

int main() {
    string s; cin >> s;
    int n = s.size();
    for (int i = 1; i <= n; i++) {
        chmax(dp[i][1],dp[i-1][2]+1);
        if (i-2 >= 0 && s[i-1] != s[i-2]) chmax(dp[i][1],dp[i-1][1]+1);
        if (i-2 >= 0) chmax(dp[i][2],dp[i-2][1]+1);
        if (i-3 >= 0 && s.substr(i-1,2) != s.substr(i-3,2)) {
            chmax(dp[i][2],dp[i-2][2]+1);
        }
    }
    int ans = max(dp[n][1],dp[n][2]);
    cout << ans << endl;
}