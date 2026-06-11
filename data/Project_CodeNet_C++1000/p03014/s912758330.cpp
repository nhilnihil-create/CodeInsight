#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(int i=cc;i>=n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const double PI = 3.1415926535;
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;

int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<int>>left(h,vector<int>(w)),right(h,vector<int>(w)),
    up(h,vector<int>(w)),down(h,vector<int>(w));
    vector<string>board(h);
    rep(i, 0, h)cin >> board[i];
    rep(i, 0, h){
        int cnt = 0; 
        rep(j, 0, w){
            if(board[i][j]=='#')cnt = 0;
            else cnt++;
            left[i][j] = cnt;
        }
    }
    rep(i, 0, h){
        int cnt = 0; 
        rrep(j, w-1, 0){
            if(board[i][j]=='#')cnt = 0;
            else cnt++;
            right[i][j] = cnt;
        }
    }
    rep(j, 0, w){
        int cnt = 0; 
        rep(i, 0, h){
            if(board[i][j]=='#')cnt = 0;
            else cnt++;
            up[i][j] = cnt;
        }
    }
    rep(j, 0, w){
        int cnt = 0; 
        rrep(i, h-1, 0){
            if(board[i][j]=='#')cnt = 0;
            else cnt++;
            down[i][j] = cnt;
        }
    }
    int ans = 0;
    rep(i, 0, h){
        rep(j, 0, w){
            chmax(ans, left[i][j]+right[i][j]+up[i][j]+down[i][j]-3);
        }
    }
    cout << ans << endl;
}