#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    int N;
    string S;
    cin >> N >> S;
    int ans = 0;
    rep(i,10) rep(j,10) rep(k,10) {
        for (int l = 0; l < N; ++l) {
            if (S.at(l) == '0' + i) {
                ++l;
                for (; l < N; ++l) {
                    if (S.at(l) == '0' + j) {
                        ++l;
                        for (; l < N; ++l) {
                            if (S.at(l) == '0' + k) {
                                ++ans;
                                l = N;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
