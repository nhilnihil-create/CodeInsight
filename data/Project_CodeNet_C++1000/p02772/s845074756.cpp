#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    bool ok = true;
    rep(i, N) {
        if (A[i] % 2 == 0 && A[i] % 3 != 0 && A[i] % 5 != 0) {
            ok = false;
            break;
        }
    }
    if (ok)
        cout << "APPROVED" << endl;
    else
        cout << "DENIED" << endl;
}