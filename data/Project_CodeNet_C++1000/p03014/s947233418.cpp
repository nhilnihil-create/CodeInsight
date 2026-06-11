#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Pl = pair<long long, long long>;
using veci = vector<int>;
using vecl = vector<long long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

int main() {
    int H,W; cin >> H >> W;
    vector<string> S(H);
    REP(i,H) cin >> S[i];
    vecveci cnt_W(H,veci(W)),cnt_H(H,veci(W));
    REP(i,H) {
        int cnt = 1;
        REP(j,W) {
            if(S[i][j] == '#') cnt = 1;
            else {
                cnt_W[i][j] = cnt;
                cnt++;
            }
        }
        for(int j = W-2; j >= 0; --j) {
            if(S[i][j] == '.' && S[i][j+1] == '.') cnt_W[i][j] = cnt_W[i][j+1];
        }
    }
    REP(j,W) {
        int cnt = 1;
        REP(i,H) {
            if(S[i][j] == '#') cnt = 1;
            else {
                cnt_H[i][j] = cnt;
                cnt++;
            }
        }
        for(int i = H-2; i >= 0; --i) {
            if(S[i][j] == '.' && S[i+1][j] == '.') cnt_H[i][j] = cnt_H[i+1][j];
        }
    }

    int ans = 0;

    REP(i,H) REP(j,W) {
        if(S[i][j] == '#') continue;
        else {
            chmax(ans,cnt_H[i][j]+cnt_W[i][j]-1);
        }
    }
    cout << ans << endl;
}
