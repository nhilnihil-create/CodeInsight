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
    int N, K;
    cin >> N >> K;

    int E = (N - 1) * (N - 2) / 2;
    vector<P> ans;
    if (K > E) {
        cout << -1 << endl;
        return 0;
    }
    else {
        repd(i, 2, N + 1) ans.push_back(P(1, i));
        int cnt = E - K;
        repd(i, 2, N) {
            repd(j, i + 1, N + 1) {
                if (cnt == 0) break;
                ans.push_back(P(i, j));
                cnt--;
            }
            if (cnt == 0) break;
        }
    }

    cout << (int)ans.size() << endl;
    rep(i, ans.size()) cout << ans[i].first << " " << ans[i].second << endl;
    return 0;
}