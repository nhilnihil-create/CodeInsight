#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
// using namespace atcoder;
void Main()
{
    ll H, W;
    cin >> H >> W;

    vector<string> S(H);
    rep(i, H) cin >> S[i];
    
    vector<vector<int>> L(H, vector<int>(W)); 
    vector<vector<int>> R(H, vector<int>(W)); 
    vector<vector<int>> U(H, vector<int>(W)); 
    vector<vector<int>> D(H, vector<int>(W)); 

    // left
    rep(y, H) {
        int cnt = 0;
        rep(x, W) {
            if (S[y][x] == '.') {
                cnt++;
            }
            else {
                cnt = 0;
            }
            L[y][x] = cnt;
        }
    }

    // right
    rep(y, H) {
        int cnt = 0;
        for (int x = W - 1; x >= 0; x--) {
            if (S[y][x] == '.') {
                cnt++;
            }
            else {
                cnt = 0;
            }
            R[y][x] = cnt;
        }
    }

    // Up
    rep(x, W) {
        int cnt = 0;
        rep(y, H) {
            if (S[y][x] == '.') {
                cnt++;
            }
            else {
                cnt = 0;
            }
            U[y][x] = cnt;
        }
    }

    // Down
    rep(x, W) {
        int cnt = 0;
        for (int y = H - 1; y >= 0; y--) {
            if (S[y][x] == '.') {
                cnt++;
            }
            else {
                cnt = 0;
            }
            D[y][x] = cnt;
        }
    }

    int res = 0;
    rep(y, H) rep(x, W) {
        res = max(res, U[y][x] + D[y][x] + L[y][x] + R[y][x] - 3);
    }
    put(res);
}
signed main(){ Main();return 0;}