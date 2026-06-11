#include <bits/stdc++.h>
#define FASTIO
using namespace std;

using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = numeric_limits<int>::max();
constexpr ll L_INF = numeric_limits<ll>::max();

//==================================

int main() {
#ifdef FASTIO
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
#endif
#ifdef FILEINPUT
    ifstream ifs("./in_out/input.txt");
    cin.rdbuf(ifs.rdbuf());
#endif

    ll N, M, V, P;
    cin >> N >> M >> V >> P;
    Vl A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end(), greater<ll>());

    Vl csum(N + 1);
    for (int i = 0; i < N; i++) {
        csum[i + 1] = csum[i] + A[i];
    }

    int left = -1, right = N;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        ll a = A[mid] + M;
        ll b = M * max(V - (N - mid) - (P - 1), 0LL);
        ll c = a * (mid - P + 1) - (csum[mid] - csum[P - 1]);
        if (mid < P) {
            left = mid;
        }
        else if (A[P - 1] > a) {
            right = mid;
        }
        else if (c < b) {
            right = mid;
        }
        else {
            left = mid;
        }
    }

    cout << left + 1 << endl;

    return 0;
}