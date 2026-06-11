#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
constexpr long long LINF = 1001001001001001001;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){ 
    int h, w; cin >> h >> w;
    vector<string> grid(h); rep(i, h)cin >> grid[i];

    vector<vector<int>> DP(h, vector<int>(w, INF));
    DP[0][0] = 0;
    if(grid[0][0] == '#')DP[0][0]++;
    rep(i, h){
        rep(j, w){
            int num = DP[i][j];
            if(i<h-1){
                if(grid[i][j]== '.' && grid[i+1][j] == '#')chmin(DP[i+1][j], num + 1);
                else chmin(DP[i+1][j], num);
            }
            if(j<w-1){
                if(grid[i][j]== '.' && grid[i][j+1] == '#')chmin(DP[i][j+1], num + 1);
                else chmin(DP[i][j+1], num);
            }
        }
    }

    cout << DP[h-1][w-1] << ln;
}

