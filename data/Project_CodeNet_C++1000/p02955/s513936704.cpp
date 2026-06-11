#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define LINF 1000000000000000000
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef pair<int, int> P;
typedef pair<long long, long long> LLP;

int main() {

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    long long sum = 0;
    rep(i,N) {
        cin >> A[i];
        sum += A[i];
    }

    sort(A.begin(), A.end());
    
    vector<long long> divisor;
    for (long long i = 1; i * i <= sum; i++) {
        if (sum % i == 0) {
            divisor.push_back(i);
            if (i != sum / i) divisor.push_back(sum / i);
        }
    }
    
    sort(divisor.begin(), divisor.end(), greater<long long>());
    long long D = divisor.size();
    rep(i,D) {

        long long x = divisor[i];

        vector<long long> m(N);
        rep(i,N) m[i] = A[i] % x;

        sort(m.begin(), m.end());

        vector<long long> minus(N, 0), plus(N, 0);
        rep(i,N) minus[i] = m[i] + (i > 0 ? minus[i - 1] : 0);
        rep(i,N) plus[N - 1 - i] = (x - m[N - 1 - i]) + (i > 0 ? plus[N - i] : 0);
        long long count = min(plus[0], minus[N - 1]);
        rep(i,N-1) count = min(count, max(minus[i], plus[i + 1]));
        if (count <= K) {
            cout << x << endl;
            return 0;
        }
    }

    return 0;
}