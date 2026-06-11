#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
// #define INF __INT32_MAX__
#define INF 1e9
#define LINF __LONG_LONG_MAX__

int main() {
    int N; cin >> N;
    vl A(N); rep(i, N) cin >> A[i];

    ll total = 0;
    rep(i, N) total ^= A[i];

    rep(i, N) {
        cout << (total ^ A[i]);
        if (i != (N - 1)) cout << " ";
    }
    cout << endl;
}
