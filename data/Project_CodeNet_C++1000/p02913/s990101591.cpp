#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vs = vector<string>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

int dp[5005][5005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = n-1; i >= 0; --i) {
        for (int j = n-1; j >= 0; --j) {
            if (s[i] == s[j]) dp[i][j] = dp[i+1][j+1] + 1;
            chmax(ans, min(dp[i][j], abs(i-j)));
        }
    }
    cout << ans << endl;
}