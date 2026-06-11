#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    int s = 0;
    rep(i, n) {
        cin >> A[i];
        s += A[i];
    }
    vector<int> B;
    for (int i = 1; i*i <= s; ++i) {
        if (s % i == 0) {
            B.push_back(i);
            B.push_back(s/i);
        }
    }
    int ans = 0;
    for (int x: B) {
        vector<int> C(n);
        int t = 0;
        rep(i, n) {
            C[i] = A[i] % x;
            t += C[i];
        }
        sort(C.begin(), C.end());
        int u = 0;
        rep(i, n-t/x) u += C[i];
        if (u <= k) {
            ans = max(ans, x);
        }
    }
    cout << ans << endl;
    return 0;
}