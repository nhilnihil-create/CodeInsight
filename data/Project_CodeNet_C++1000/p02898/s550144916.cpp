#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int N,K;
    cin >> N >> K;
    vector<int> gr(N);

    rep (i, N) cin >> gr[i];

    int cnt = 0;
    rep (i, N) {
        if (gr[i] >= K)
        {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}