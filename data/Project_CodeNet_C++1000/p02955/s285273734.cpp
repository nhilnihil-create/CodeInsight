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
        vector<long long> plus, minus;
        rep(j,N) {
            long long p = A[j] % x;
            if (p <= (x - p)) plus.push_back(p);
            else minus.push_back(x - p);
        }
        sort(plus.begin(), plus.end());
        sort(minus.begin(), minus.end());
        deque<long long> deq_plus, deq_minus;
        rep(j,plus.size()) deq_plus.push_back(plus[j]);
        rep(j,minus.size()) deq_minus.push_back(minus[j]);
        long long count = 0;
        while (!deq_plus.empty() || !deq_minus.empty()) {
            if (deq_plus.empty()) {
                long long& mb = deq_minus.back(); deq_minus.pop_back();
                deq_plus.push_back(x - mb);
            } else if (deq_minus.empty()) {
                long long& pb = deq_plus.back(); deq_plus.pop_back();
                deq_minus.push_back(x - pb);
            }
            long long& p = deq_plus.front(); deq_plus.pop_front();
            long long& m = deq_minus.front(); deq_minus.pop_front();
            if (p == m) count += p;
            else if (p > m) {
                count += m;
                p -= m;
                deq_plus.push_front(p);
            } else {
                count += p;
                m -= p;
                deq_minus.push_front(m);
            }
        }
        if (count <= K) {
            cout << x << endl;
            return 0;
        }
    }

    return 0;
}