#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<long long, long long> P;
bool IsPrime(long long N) {
    for (long long i = 2; i * i <= N; i++) {
        if (N % i == 0) return false;
    }
    return true;
}
vector<P> prime_factorization (long long N) {
    vector<P> A;
    long long tmp = N;
    for (long long i = 2; i * i <= N; i++) {
        if (N % i == 0 && IsPrime(i)) {
            A.push_back(make_pair(i, 0));
            while (tmp % i == 0) {
                A.back().second++;
                tmp /= i;
            }
        }
    }
    if (tmp != 1) A.push_back(make_pair(tmp, 1));
    return A;
}

int main() {
    long long N; cin >> N;
    vector<P>A = prime_factorization(N);
    long long ans = 0;
    for (long long i = 0; i < A.size(); i++) {
        long long j = 1;
        while (A.at(i).second >= j) {
            ans++;
            A.at(i).second -= j;
            j++;
        }
    }
    cout << ans << endl;
}