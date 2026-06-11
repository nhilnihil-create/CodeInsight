#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define Rep(i, n) for (int i = 0; i < (int)(n); i++)
#define BitRep(i, n) for (int i = 0; i < (int)(1 << n); i++)
#define All(vec) vec.begin(), vec.end()
#define Sum(vec) accumulate(vec.begin(), vec.end(), 0)
#define Sort(vec) sort(vec.begin(), vec.end())
#define Reverse(vec) reverse(vec.begin(), vec.end())
#define Next_permutation(vec) next_permutation(vec.begin(), vec.end())
#define PI acos(-1)

int main() {
    int N, K;
    cin >> N >> K;
    vector<double> pro(N);
    Rep(i, N) {
        int p;
        cin >> p;
        pro[i] = (double)(p + 1) / 2;
    }
    double ans = 0;
    Rep(i, K) {
        ans += pro[i];
    }
    double x = ans;
    for (int i = K; i < N; i++) {
        x += pro[i] - pro[i - K];
        ans = max(ans, x);
    }
    printf("%.6f\n", ans);
    return 0;
}