#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int N;
    string S;
    cin >> N >> S;
    
    vector<int> rgb_counter(3);
    rep(i, N) {
        if (S.at(i) == 'R') rgb_counter.at(0)++;
        else if (S.at(i) == 'G') rgb_counter.at(1)++;
        else if (S.at(i) == 'B') rgb_counter.at(2)++;
    }
    
    // coindition 1
    ll ans = 1;
    rep(i, 3) ans *= rgb_counter.at(i);
    
    // converse of condition 2
    rep(j, N) {
        rep(i, j) {
            int k = j + (j - i);
            if (k < N) {
                if (S.at(i) == S.at(j)) continue;
                else if (S.at(i) == S.at(k)) continue;
                else if (S.at(k) == S.at(j)) continue;
                ans--;
            }
        }
    }
    
    cout << ans << endl;
}
