#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using vll = vector<long long>;
using vp = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

const int INF = 1001001001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    s += '0';
    int n = s.size();
    vvi dp(n+1, vi(2, INF));
    dp[0][0] = 0;
    rep(i, n) rep(j, 2) {
        int x = s[i] - '0';
        x += j;
        if (x < 10) chmin(dp[i+1][0], dp[i][j] + x);
        if (x > 0) chmin(dp[i+1][1], dp[i][j] + 10 - x);
    }
    cout << dp[n][0] << endl;
}