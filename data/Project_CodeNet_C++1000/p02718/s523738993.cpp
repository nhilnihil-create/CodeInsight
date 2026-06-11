#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {

    int N, M;
    cin >> N >> M;

    vector<int> A(N);

    int S = 0;

    rep(i, N) {
        cin >> A[i];
        S += A[i];
    }

    int ans = 0;

    for(int x : A) {
        if (x >= float(S) / (4*float(M))) {
            ans++;
        }
    }

    if (ans >= M) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}