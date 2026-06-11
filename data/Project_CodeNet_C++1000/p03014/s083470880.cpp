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
int main()
{
    int H, W;
    cin >> H >> W;
    vector<string> HW(H);
    rep(i, H) cin >> HW[i];

    vector<vector<int>> R(H + 1, vector<int>(W + 1, 0));
    vector<vector<int>> C(H + 1, vector<int>(W + 1, 0));

    repd(i, 1, H + 1) {
        repd(j, 1, W + 1) {
            if (HW[i - 1][j - 1] == '.') {
                R[i][j] += R[i][j - 1] + 1;
            }
        }
    }

    repd(j, 1, W + 1) {
        repd(i, 1, H + 1) {
            if (HW[i - 1][j - 1] == '.') {
                C[i][j] += C[i - 1][j] + 1;
            }
        }
    }

    repd(i, 1, H + 1) {
        int ct = R[i][W];
        for (int j = W; j > 0; j--) {
            if (R[i][j] == 0) ct = R[i][j - 1];
            else R[i][j] = ct;
        }
    }

    repd(j, 1, W + 1) {
        int ct = C[H][j];
        for (int i = H; i > 0; i--) {
            if (C[i][j] == 0) ct = C[i - 1][j];
            else C[i][j] = ct;
        }
    }
/*
    repd(i, 1, H + 1) {
        repd(j, 1, W + 1) {
            cout << R[i][j] << " ";
        }
        cout << endl;
    }
*/
    int ans = 0;
    repd(i, 1, H + 1) {
        repd(j, 1, W + 1) {
            chmax(ans, R[i][j] + C[i][j]);
        }
    }

    cout << max(0, ans - 1) << endl;
    return 0;
}