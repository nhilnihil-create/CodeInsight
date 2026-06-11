#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for (int i = m; i < n; ++i)

int main() {
    int N; cin >> N;
    vector<int> A(N);
    rep(i, 0, N) cin >> A[i];
    sort(A.begin(), A.end());
    using P = pair<int, int>;
    vector<P> ans;
    rep(i, 1, N - 1) {
        if(A[i] > 0) {
            ans.push_back({A[0], A[i]});
            A[0] -= A[i];
        } else {
            ans.push_back({A[N - 1], A[i]});
            A[N - 1] -= A[i];
        }
    }
    ans.push_back({A[N - 1], A[0]});
    cout << A[N - 1] - A[0] << '\n';
    for(auto &a : ans) cout << a.first << " " << a.second << '\n';
    return 0;
}
