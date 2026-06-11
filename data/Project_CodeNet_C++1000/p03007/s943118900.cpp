#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repr(i, a, b) for (int i=a; i<(b); ++i)
#define reprev(i, n) for (int i=n-1; i>=0; --i)
#define reprrev(i, a, b) for (int i=b-1; i>=(a); --i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    cout << fixed << setprecision(10);
    
    int N; cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    sort(A.begin(), A.end());
    int amin = A[0], amax = A[N-1];
    // int l = 0, r = N-1;

    vector<P> ans;
    repr(i, 1, N-1) {
        if (A[i] < 0) {
            ans.emplace_back(amax, A[i]);
            amax -= A[i];
        } else {
            ans.emplace_back(amin, A[i]);
            amin -= A[i];
        }
    }
    cout << abs(amax - amin) << endl;
    ans.emplace_back(amax, amin);
    rep(i, ans.size()) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}