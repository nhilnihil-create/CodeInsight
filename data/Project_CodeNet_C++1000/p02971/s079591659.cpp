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
    rep(i, N) cin >> A[i];
    int mx = *max_element(A.begin(), A.end());
    if (count(A.begin(), A.end(), mx) == 1) {
        int second = 0;
        rep(i, N) {
            if (A[i] == mx) continue;
            if (A[i] > second) second = A[i];
        }
        rep(i, N) {
            if (A[i] == mx) printf("%d\n", second);
            else printf("%d\n", mx);
        }
    } else {
        rep(i, N) printf("%d\n", mx);
    }
    return 0;
}