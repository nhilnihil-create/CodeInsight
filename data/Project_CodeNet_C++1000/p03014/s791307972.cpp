#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <numeric>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;
const double pi = acos(-1);

int main() {
    ll h, w;
    cin >> h >> w;
    
    vector<string> board(h);
    rep(i, h) {
        cin >> board[i];
    }
    
    vvl L(h, vl(w));  // L[i][j] : (i,j)の左側の障害物のないマスの連続している個数
    rep(i, h) {
        for(ll j = 1; j < w; j++) {
            if(board[i][j-1] == '#') {
                L[i][j] = 0;
            }
            else {
                L[i][j] = L[i][j-1] + 1;
            }
        }
    }

    vvl R(h, vl(w));  // R[i][j] : (i,j)の右側の障害物のないマスの連続している個数
    rep(i, h) {
        for(ll j = w-2; j >= 0; j--) {
            if(board[i][j+1] == '#') {
                R[i][j] = 0;
            }
            else {
                R[i][j] = R[i][j+1] + 1;
            }
        }
    }

    vvl U(h, vl(w));  // U[i][j] : (i,j)の上側の障害物のないマスの連続している個数
    for(ll i = 1; i < h; i++) {
        rep(j, w) {
            if(board[i-1][j] == '#') {
                U[i][j] = 0;
            }
            else {
                U[i][j] = U[i-1][j] + 1;
            }
        }
    }

    vvl D(h, vl(w));  // D[i][j] : (i,j)の下側の障害物のないマスの連続している個数
    for(ll i = h-2; i >= 0; i--) {
        rep(j, w) {
            if(board[i+1][j] == '#') {
                D[i][j] = 0;
            }
            else {
                D[i][j] = D[i+1][j] + 1;
            }
        }
    }

    ll ans = 0;
    rep(i, h) {
        rep(j, w) {
            if(board[i][j] == '#') {
                continue;
            }
            chmax(ans, L[i][j] + R[i][j] + U[i][j] + D[i][j] + 1);
        }
    }

    out(ans);
    re0;
}