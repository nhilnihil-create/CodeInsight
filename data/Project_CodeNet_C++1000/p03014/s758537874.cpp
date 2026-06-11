//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;



int main() {
    int h, w;
    cin >> h >> w;
    vs s(h);
    rep(i, h) {
        cin >> s[i];
    }

    int now = 0;
    vvi board(h, vi(w));
    rep(i, h) {
        rep(j, w) {
            if(s[i][j] == '.') {
                ++now;
            } else {
                rep(k, now) {
                    board[i][j-1-k] = now;
                }
                now = 0;
            }
        }
        rep(k, now) {
            board[i][w-1-k] = now;
        }
        now = 0;
    }
    int ans = 0;
    rep(j, w) {
        rep(i, h) {
            if(s[i][j] == '.') {
                ++now;
            } else {
                rep(k, now) {
                    board[i-1-k][j] += now;
                    ans = max(ans, board[i-1-k][j]);
                }
                now = 0;
            }
        }
        rep(k, now) {
            board[h-1-k][j] += now;
            ans = max(ans, board[h-1-k][j]);
        } 
        now = 0;
    }

    cout << --ans << endl;
}