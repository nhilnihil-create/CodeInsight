#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (double i=(a);i<(b);i++)
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

    vector<int> p(N), sum(N + 1, 0);
    vector<double> P(1001, 0);

    rep(i, N) {
        cin >> p[i];
        sum[i + 1] = sum[i] + p[i];
    }

    int m = 0;
    int index = 0;
    repd(i, K, N + 1) {
        if (m < sum[i] - sum[i - K]) {
            m = sum[i] - sum[i - K];
            index = i - K;
        }
    }

    double ans = 0;
    repd(i, 1, 1001) {
        repd(j, 1, i + 1) {
            P[i] += j / i;
        }
    }

    repd(i, index, index + K) {
        ans += P[p[i]];
    }

    cout << fixed << setprecision(11) << ans << endl;
    return 0;
}
