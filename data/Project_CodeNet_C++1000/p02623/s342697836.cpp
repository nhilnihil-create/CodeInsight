#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> Pil;

ll N, M, K;
const int MAX = 200010;
ll A[MAX], B[MAX];

ll binary_search(ll num, vector<ll> vec) {
    //ll ret = 0;
    int left = 0;
    int right = vec.size() - 1;
    while (left < right) {
        int mid = (left + right)/2;
        if (vec[mid] == num) {
            //ret = mid+1;
            right = mid;
            break;
        }
        else if (vec[mid] < num) {
            left = mid + 1;
            //ret = mid + 1;
        }
        else {
            right = mid;
            //ret = mid;
        }
    }
    return right;
}

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
