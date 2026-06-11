#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const ll mod = 1000000007;
const double eps = 1e-8;

#ifdef DEBUG
#include "inc/debug.hpp"
#else
#define debug(...) 42
#endif

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i=0; i<N; ++i) cin >> A[i];

    int S = accumulate(A.begin(), A.end(), 0);
    int cnt = 0;
    for (int i=0; i<N; ++i) {
        if (A[i] * 4 * M >= S) {
            cnt ++;
        }
    }
    cout << (cnt >= M ? "Yes" : "No") << endl;
    return 0;
}
