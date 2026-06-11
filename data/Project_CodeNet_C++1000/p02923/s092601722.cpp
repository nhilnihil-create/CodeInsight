#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    rep(i,N) cin >> H.at(i);
    int ans = 0;
    int cnt = 0;
    rep(i,N-1) {
        if (H.at(i) >= H.at(i+1)) cnt++;
        if (H.at(i) < H.at(i+1) || i == N - 2) {
            ans = max(ans, cnt);
            cnt = 0;
        }
    }
    cout << ans << endl;
}
