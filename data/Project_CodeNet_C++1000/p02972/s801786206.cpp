#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for(auto &e : A) cin >> e;
    vector<int> ans;
    for(int i = N - 1; i >= 0; --i) {
        int n = i + 1;
        for(int j = i + n; j < N; j += n) A[i] ^= A[j];
    }
    rep(i, N) if(A[i]) ans.push_back(i + 1);
    cout << ans.size() << '\n';
    for(auto &e : ans) cout << e << " ";
    return 0;
}
