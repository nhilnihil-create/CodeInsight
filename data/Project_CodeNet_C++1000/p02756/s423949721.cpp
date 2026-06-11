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
    string A, L = "", R = "";
    int Q;
    cin >> A >> Q;

    int cnt = 0;
    rep(i, Q) {
        int q;
        cin >> q;
        if (q == 1) cnt = (cnt + 1) % 2;
        else {
            int f;
            string c;
            cin >> f >> c;
            if (f == 1) {
                if (cnt) {
                    R += c;
                }
                else {
                    string tmp = c + L;
                    L = tmp;
                }
            }
            else {
                if (cnt) {
                    string tmp = c + L;
                    L = tmp;
                }
                else {
                    R += c;
                }
            }
        }
    }

    string ans = "";
    if (cnt) {
        reverse(all(R));
        reverse(all(A));
        reverse(all(L));
        ans += R + A + L;
    }
    else ans += L + A + R;

    cout << ans << endl;
    return 0;
}