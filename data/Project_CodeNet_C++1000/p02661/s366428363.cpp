#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    rep(i, N) cin >> A[i] >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    if (N&1) {
        int left, right;
        left = A[N/2]; right = B[N/2];
        int ans = right - left + 1;
        cout << ans << '\n';        
    } else {
        double left, right;
        left = (double)(A[N/2] + A[N/2 - 1]) / 2;
        right = (double)(B[N/2] + B[N/2 - 1]) / 2;
        int ans = (right - left) / 0.5 + 1;
        cout << ans << '\n';
    }
    return 0;
}