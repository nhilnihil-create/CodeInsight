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
    int N, M;
    cin >> N >> M;
    vector<int> A(N + 1);
    Rep(i, M) cin >> A[i];
    vector<int> dp(N + 1);
    int index = 0;
    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        if (i == A[index]) {
            index++;
            continue;
        }
        else if (i == 1) dp[1] = 1;
        else dp[i] = (dp[i - 2] + dp[i - 1]) % 1000000007;
    }
    cout << dp[N] << endl;
    return 0;
}