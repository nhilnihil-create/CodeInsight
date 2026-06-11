#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    rep(i, n) cin >> A[i] >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());
    int ans = 0;
    if (n%2 == 1) {
        ans = B[n/2] - A[n/2] + 1;
    } else {
        int min_m = A[n/2-1] + A[n/2];
        int max_m = B[n/2-1] + B[n/2];
        ans = max_m - min_m + 1;
    }
    cout << ans << endl;
    return 0;
}