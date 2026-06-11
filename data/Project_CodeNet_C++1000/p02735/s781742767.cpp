#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int main(){
    cout << fixed << setprecision(10);
    int h,w;
    cin >> h >> w;
    vector<vector<int>> dp(h+10,vector<int>(h+10, inf));
    string s[h];
    rep(i,h) cin >> s[i];
    if(s[0][0] == '.') dp[0][0] = 0;
    else dp[0][0] = 1;
    rep(i,h){
        rep(j,w){
            rep(k,2){
                int dx[] = {1, 0};
                int dy[] = {0, 1};
                int ni = i + dx[k], nj = j + dy[k];
                if(ni >= h || nj >= w) continue;
                if(s[ni][nj] == '#' && s[i][j] == '.') chmin(dp[ni][nj], dp[i][j] + 1);
                else chmin(dp[ni][nj], dp[i][j]);
            }
        }
    }
    cout << dp[h-1][w-1] << endl;
    return 0;
}
