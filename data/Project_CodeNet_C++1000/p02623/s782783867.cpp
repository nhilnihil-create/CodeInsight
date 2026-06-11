#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> Pil;

ll N, M, K;
const int MAX = 200010;
ll A[MAX], B[MAX];

int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];
    
    vector<ll> sum_B(M);
    sum_B[0] = B[0];
    for (int i = 1; i < M; i++) {
        sum_B[i] = sum_B[i-1] + B[i];
    }

    int ans = 0;
    ll sum_A = 0;
    int tmp = upper_bound(sum_B.begin(), sum_B.end(), K-sum_A) - sum_B.begin();
    ans = max(ans, tmp);
    for (int i = 0; i < N; i++) {
        sum_A += A[i];
        if (sum_A <= K) {
            int tmp2 = upper_bound(sum_B.begin(), sum_B.end(), K-sum_A) - sum_B.begin();
            ans = max(ans, tmp2 +i+1);
        }
    }

    cout << ans << endl;

    return 0;
}
