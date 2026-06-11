#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    double med_A, med_B;
    ll ans;
    if (N % 2) {
        med_A = A[N/2];
        med_B = B[N/2];
        ans = med_B - med_A + 1;
    } else {
        med_A = (A[N/2-1] + A[N/2]) / 2.0;
        med_B = (B[N/2-1] + B[N/2]) / 2.0;
        ans = 2 * (med_B - med_A) + 1;
    }
    cout << ans << endl;
}