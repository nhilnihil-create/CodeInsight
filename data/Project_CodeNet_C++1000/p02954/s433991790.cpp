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
    string S;
    cin >> S;

    int len = (int)S.size();
    vector<int> cnt(len), ans(len);

    int ct = 1;
    rep(i, len - 1) {
        cnt[i] = ct;
        ct++;
        if (S[i] != S[i + 1]) ct = 1;
    }
    cnt[len - 1] = ct;

    int rmax;
    for (int i = len - 1; i >= 0; i--) {
        if (S[i] == 'L') {
            int lcnt = cnt[i] - 1;
            lcnt *= -1;
            if (lcnt % 2) lcnt--;
            ans[i + lcnt]++;
        }
        else {
            if (S[i + 1] == 'L') rmax = cnt[i];
            int rcnt = rmax - cnt[i];
            if (rcnt % 2) rcnt++;
            ans[i + rcnt]++;
        }
    }

    rep(i, len) cout << ans[i] << endl;
    return 0;
}