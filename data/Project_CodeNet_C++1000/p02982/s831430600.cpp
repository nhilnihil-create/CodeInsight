#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N, D;
    cin >> N >> D;
    vector<int> X[N];
    rep(i, N) {
        vector<int> A(D);
        rep(i, D) cin >> A[i];
        X[i] = A;
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            int temp = 0; // 平方数
            rep(k, D) {
                int x = X[i][k] - X[j][k];
                temp += x * x;
            }
            int y = sqrt(temp);
            if (temp == y * y) ans++;
        }        
    }
    cout << ans << '\n';
    return 0;
}