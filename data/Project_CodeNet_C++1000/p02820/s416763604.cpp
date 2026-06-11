#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
#define INF __INT32_MAX__
#define LINF __LONG_LONG_MAX__

int getcurr(int prev, int next) {
    int ans = -1;
    rep(i, 3) {
        if (i != prev && i != next) {
            ans = i;
            break;
        }
    }
    return ans;
}

int main() {
    int N, K; cin >> N >> K;
    vi score(3); rep(i, 3) cin >> score[i];
    string T; cin >> T;
    vi ct(T.size());
    rep(i, T.size()) {
        switch (T.at(i)) {
            case 'r':
                ct[i] = 0;
                break;
            case 's':
                ct[i] = 1;
                break;
            case 'p':
                ct[i] = 2;
                break;
        }
    }

    ll ans = 0;
    // Tの添字はK未満でループする
    for (int a = 0; a < K; a++) {
        int prev = -1;
        for (int b = a; b < N; b += K) {

            if (ct[b] == prev) {
                if (b + K < N) {
                    prev = getcurr(ct[b], ct[b + K]);
                }
            } else {
                prev = ct[b];
                int j = (ct[b] + 2) % 3;
                ans += score[j];
            }
        }
    }

    cout << ans << endl;
}