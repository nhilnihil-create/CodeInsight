#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define LINF 1000000000000000000
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef pair<int, int> P;
typedef pair<long long, long long> LLP;

bool check(long long N, long long K, vector<long long> A, vector<long long> F, long long x) {
    long long left = K;
    rep(i,N) {
        long long minimum = x / F[i];
        if (A[i] > minimum) left -= A[i] - minimum;
        if (left < 0) return false;
    }
    return true;
}

int main() {

    long long N, K;
    cin >> N >> K;
    vector<long long> A(N), F(N);
    rep(i,N) cin >> A[i];
    rep(i,N) cin >> F[i];

    sort(A.begin(), A.end(), greater<int>());
    sort(F.begin(), F.end());

    long long bottom = 0;
    long long top = A[0] * F[N - 1];

    while (bottom != top) {
        long long x = bottom + (top - bottom) / 2;
        if (check(N, K, A, F, x)) top = x;
        else bottom = x + 1;
    }

    cout << bottom << endl;

    return 0;
}