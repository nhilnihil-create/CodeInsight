#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N;
    cin >> N;
    vector<int> B(N);
    rep(i,N-1) cin >> B.at(i);
    int ans = 0;

    rep(i,N) {
        if (i == 0) {
            ans += B.at(0);
        } else if (i == N - 1) {
            ans += B.at(N - 2);
        } else {
            ans += min(B.at(i), B.at(i - 1));
        }
    }
    cout << ans << endl;
}
