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
    int M = 1 << N;
    vector<int> A(M);
    rep(i, M) cin >> A[i];
    sort(A.begin(), A.end());
    vector<int> slimes;
    slimes.push_back(A.back());
    A.back() = -1;
    rep(i, N) {
        sort(slimes.begin(), slimes.end());
        vector<int> prev = slimes;
        int cur = M-1;
        while (!prev.empty() && cur >= 0) {
            if (A[cur] == -1) {
                cur--; continue;
            }
            if (A[cur] < prev.back()) {
                slimes.push_back(A[cur]);
                A[cur] = -1;
                prev.pop_back();
            }
            cur--;
        }
        if (!prev.empty()) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
    // ll, 0, -, 1i, for s&g, debug
}