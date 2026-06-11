#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define all(v) v.begin(), v.end()

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> sunuke(N,0);

    rep(i, K) {
        int d;
        cin >> d;
        rep(j, d) {
            int a;
            cin >> a;
            sunuke[a-1]++;
        }
    }

    int ans = 0;
    rep(i, N) {
        if (sunuke[i] == 0) {
            ans++;
        }
    }
    cout << ans << endl;
    
    return 0;
}