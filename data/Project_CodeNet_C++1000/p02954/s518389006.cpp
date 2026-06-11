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
    vector<int> cnt(len);

    int l = 1;
    repd(i, 1, len) {
        if (S[i - 1] == 'L') l++;
        else l = 1;
        if (S[i] == 'L') cnt[i] = l;
    }

    int r = 1;
    for (int i = len - 2; i >= 0; i--) {
        if (S[i + 1] == 'R') r++;
        else r = 1;
        if (S[i] == 'R') cnt[i] = r;
    }

    vector<int> ans(len);

    rep(i, len) {
        if (cnt[i] % 2) {
            if (S[i] == 'R') {
                ans[i + cnt[i] - 1]++;
            }
            else {
                ans[i - cnt[i] + 1]++;
            }
        }
        else {
            if (S[i] == 'R') {
                ans[i + cnt[i]]++;
            }
            else {
                ans[i - cnt[i]]++;
            }
        }
    }

    rep(i, len) cout << ans[i] << endl;
    return 0;
}