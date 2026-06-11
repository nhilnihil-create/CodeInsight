#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define all(v) v.begin(), v.end()

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> H(N,0);
    vector<int> count_H(N,1);
    rep(i, N) cin >> H[i];
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        if (H[a-1] <= H[b-1]) {
            count_H[a-1] = 0;
        }
        if (H[b-1] <= H[a-1]) {
            count_H[b-1] = 0;
        }
        
    }

    int count = 0;
    rep(i, N) count += count_H[i];
    cout << count << endl;
    return 0;
}