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
    string ans = "Yes";
    if (N > 1) {
        for (int i = N - 1; i > 0; --i) {
            if (H.at(i - 1) - 1 > H.at(i)) {
                ans = "No";
                break;
            } else if (H.at(i - 1) - 1 == H.at(i)) {
                --H.at(i - 1);
            }
        }
    }
    cout << ans << endl;
}
