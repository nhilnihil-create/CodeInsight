#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (a); i > (b); i--)
#define ALL(a) (a).begin(), (a).end()

int main() {
    ll N, A[100000], S = 0;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
        S ^= A[i];
    }
    REP(i, N) A[i] &= ~S;

    int r = 0;
    vector<int> top(N);
    RREP(i, 61) {
        int j = r;
        for (; j < N; j++) {
            if (A[j] >> i & 1) {
                swap(A[r], A[j]);
                break;
            }
        }
        if (j == N) continue;
        top[r] = i;
        REP(k, N) if (k != r && (A[k] >> i & 1)) A[k] ^= A[r];
        r++;
    }

    ll x = 0;
    RREP(i, 61) {
        ll nx = x | (1LL << i);
        REP(j, r) if (nx >> top[j] & 1) nx ^= A[j];
        if ((nx & (x | (1LL << i))) == 0) x |= (1LL << i);
    }
    cout << S + x * 2 << endl;
    return 0;
}
