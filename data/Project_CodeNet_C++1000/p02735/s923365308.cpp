#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;
using ll = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;

int H, W;
vector<string> S;
vvi board(101, vi(101));
vector<pair<int, int> > dd;

void dfs(int i, int j) {
    if(i > H-1 || j > W-1){
        return;
    }
    if(!board[i][j+1] || !board[i+1][j]){
        return;
    }
    int u, l;
    if(S[i][j+1] == S[i+1][j+1]){
        u = board[i][j+1];
    } else {
        u = 1 + board[i][j+1];
    }
    if(S[i+1][j] == S[i+1][j+1]) {
        l = board[i+1][j];
    } else {
        l = 1 + board[i+1][j];
    }
    board[i+1][j+1] = min(u, l);
    //cout << i+1 << ',' << j+1 << endl;
    dfs(i+1, j);
    dfs(i, j+1);
}

int main() {
    cin >> H >> W;
    S.push_back("");
    rep(i, W+1) {
        S[0].push_back('.');
    }
    rep (i, H) {
        S.push_back("");
        S[i+1] += '.';
        string r;
        cin >> r;
        S[i+1] += r;
        /*rep(j, W){
            S[i+1] += '#';
        }*/
        board[i+1][0] = 500;
    }
    rep(i, W) {
        board[0][i+1] = 500;
    }
    board[0][1] = 1;
    board[1][0] = 1;
    dfs(0, 0);
    cout << board[H][W]/2 << '\n';
}