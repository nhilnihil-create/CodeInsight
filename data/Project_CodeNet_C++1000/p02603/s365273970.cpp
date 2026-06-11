#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
#define INF __INT32_MAX__
#define LINF __LONG_LONG_MAX__

int main() {
    int N;
    cin >> N;
    vi A(N);
    rep(i, N) { cin >> A[i]; }

    ll money = 1000;
    rep(i, N - 1) {
        if (A[i] < A[i + 1]) {
            ll stock = money / A[i];
            ll mod = money % A[i];
            money = stock * A[i + 1] + mod;
        }
    }

    cout << money << endl;
}