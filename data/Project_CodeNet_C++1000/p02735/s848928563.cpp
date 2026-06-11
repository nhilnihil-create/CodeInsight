#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0};
const vector<int> dy = {0, 1};
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;

int h,w;
vector<string>board;

ll solve(){
    vector<vector<ll>>dp(h, vector<ll>(w,inf));
    if(board[0][0]=='#')dp[0][0]=1;
    else dp[0][0]=0;
    rep(i, 0, h){
        rep(j, 0, w){
            rep(k, 0, 2){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx>=h||ny>=w)continue;
                int add = 0;
                if(board[nx][ny]=='#' && board[i][j]=='.')add++;
                chmin(dp[nx][ny], dp[i][j]+add);
            }
        }
    }
    return dp[h-1][w-1];
}
int main() {
    cin >> h >> w;
    board.resize(h);
    rep(i, 0, h)cin >> board[i];
    cout << solve() << endl;
}