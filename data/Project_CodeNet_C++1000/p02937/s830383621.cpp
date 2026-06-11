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
    string s, t;
    cin >> s >> t;

    int slen = s.size();
    vector<vector<int>> sindex(26, vector<int>(slen + 2));

    rep(i, slen) {
        sindex[s[i] - 'a'][i + 1] = i + 1;
    }

    rep(i, 26) {
        int ct = 0;
        for (int j = slen; j >= 1; j--) {
            if (sindex[i][j] != 0) {
                ct = sindex[i][j];
            }
            sindex[i][j] = ct;
        }
    }

    ll ans = 0;
    int before = 0;

    rep(i, t.size()) {
        int now = sindex[t[i] - 'a'][before + 1];
        if (now == 0) now = sindex[t[i] - 'a'][1];
        if (now == 0) {
            ans = -1;
            break;
        }
        if (before < now) {
            ans -= before;
            ans += now;
        }
        else {
            ans -= before;
            ans += now + slen;
        }
        before = now;
    }

    cout << ans << endl;
    return 0;
}