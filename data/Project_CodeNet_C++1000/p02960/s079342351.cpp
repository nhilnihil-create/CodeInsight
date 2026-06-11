#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define Rep(i,n) for(int i = 1; i <= n; i++)
#define sz(x) int(x.size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesorNo(a) printf(a ? "Yes\n" : "No\n")
#define endl '\n'
#define fi first
#define se second
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
template<class T> using V = vector<T>;
const int dx[] = {0,1,0,-1,1,1,-1,-1};
const int dy[] = {1,0,-1,0,1,-1,-1,1};
const int inf = (1<<30)-1;
const ll infll = (1LL<<62)-1;
ll ceil(const ll &a, const ll &b){return ((a)+(b)-1)/b;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const int mod = 1e9+7;
int dp[100005][13] = {};

int main(){

    string s;
    cin >> s;
    int n = sz(s);

    dp[0][0] = 1;
    rep(i,n) {
        rep(j,13) {
            if(s[i] >= '0' && s[i] <= '9') {
                int c = s[i] - '0';
                dp[i+1][(j*10+c)%13] += dp[i][j];
                dp[i+1][(j*10+c)%13] %= mod;
            }
            else {
                rep(c,10) {
                    dp[i+1][(j*10+c)%13] += dp[i][j];
                    dp[i+1][(j*10+c)%13] %= mod;
                }
            }
        }
    }

    int ans = dp[n][5];
    cout << ans << endl;
}