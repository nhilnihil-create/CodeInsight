#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
//cout << setprecision(20) << 

int main() {
    ll N; cin >> N;
    vector<ll> A(N + 1);
    ll sum = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        if (i % 2 == 1) {
            sum += A[i];
        }
        else {
            sum -= A[i];
        }
    }
    sum /= 2;
    vector<ll> ans(N + 1, 0);
    ans[1] = sum;
    cout << sum * 2 << " ";
    for (int i = 2; i <= N; ++i) {
        ans[i] = A[i - 1] - ans[i - 1];
        cout << ans[i] * 2 << " ";
    }
}