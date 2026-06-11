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
    vector<int> so = A;
    sort(so.rbegin(), so.rend());
    rep(i, N) {
        int ans = so[0];
        if (A[i] == so[0]) ans = so[1];
        printf("%d\n", ans);
    }
    return 0;
}