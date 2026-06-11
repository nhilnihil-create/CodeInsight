#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {

    int K, N;
    cin >> K >> N;

    vector<int> A(N);
    rep(i, N) cin >> A[i];

    A.push_back(K+A[0]);

    int l = 0;

    rep(i, N) {
        l = max(l, A[i + 1] - A[i]);
    }

    cout << K - l << endl;

    return 0;
}