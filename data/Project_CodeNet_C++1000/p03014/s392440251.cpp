#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;

const int MAX_V = 3000;

int X[MAX_V][MAX_V], Y[MAX_V][MAX_V];
int main()
{
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, H) cin >> S[i];

    repd(i, 1, H + 1) {
        repd(j, 1, W + 1) {
            if (S[i - 1][j - 1] == '.') {
                X[i][j] = X[i][j - 1] + 1;
            }
        }
    }

    repd(i, 1, H + 1) {
        int ct = X[i][W];
        for (int j = W - 1; j >= 1; j--) {
            if (X[i][j] == 0) {
                ct = 0;
                continue;
            }
            if (ct == 0) ct = X[i][j];
            else {
                X[i][j] = ct;
            }
        }
    }

    repd(j, 1, W + 1) {
        repd(i, 1, H + 1) {
            if (S[i - 1][j - 1] == '.') {
                Y[i][j] = Y[i - 1][j] + 1;
            }
        }
    }

    repd(j, 1, W + 1) {
        int ct = Y[H][j];
        for (int i = H - 1; i >= 1; i--) {
            if (Y[i][j] == 0) {
                ct = 0;
                continue;
            }
            if (ct == 0) ct = Y[i][j];
            else {
                Y[i][j] = ct;
            }
        }
    }
/*
    rep(i, H + 1) {
        rep(j, W + 1) {
            cout << X[i][j] << ":" << Y[i][j] << " ";
        }
        cout << endl;
    }
*/
    int ans = 0;
    rep(i, H) {
        rep(j, W) {
            chmax(ans, X[i + 1][j + 1] + Y[i + 1][j + 1] - 1);
        }
    }

    cout << ans << endl;
    return 0;
}