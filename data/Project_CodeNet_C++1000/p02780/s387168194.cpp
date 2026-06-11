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
    vector<double> p(N), sum(N + 1, 0);

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
    repd(i, index, index + K) {
        double res = ((p[i] + 1) * p[i]) / 2.0;
        ans += res / p[i];
    }

    printf("%.8lf", ans);
    return 0;
}
