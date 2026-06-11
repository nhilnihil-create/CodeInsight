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
    vector<int> P(N);
    rep(i, N) cin >> P[i];
    vector<int> A = P;
    sort(A.begin(), A.end());
    int cnt = 0;
    rep(i, N) {
        if (A[i] != P[i]) cnt++;
    }
    bool bl = (cnt == 0 || cnt == 2);
    puts(bl ? "YES" : "NO");
    return 0;
}