#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {

    int N;
    cin >> N;

    vector<double> A(N);

    double q = 0.0;

    rep(i, N) {
        cin >> A[i];
        q += 1.0 / A[i];
    }

    cout << setprecision(16) << 1.0 / q << endl;

    return 0;
}