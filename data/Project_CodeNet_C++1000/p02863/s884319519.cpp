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
    int N, T;
    cin >> N >> T;
    vector<P> AB(N);
    rep(i, N) {
        int A, B;
        cin >> A >> B;
        AB[i] = {A, B};
    }

    sort(all(AB));

    vector<vector<ll>> dp(N + 1, vector<ll>(T + 1));

    rep(i, N) {
        rep(j, T) {
            chmax(dp[i + 1][j], dp[i][j]);
            chmax(dp[i + 1][min(T, j + AB[i].first)], dp[i][j] + AB[i].second);
        }
    }

    ll ans = 0;
    rep(i, N) {
        chmax(ans, dp[i + 1][T]);
    }
    cout << ans << endl;
    return 0;
}