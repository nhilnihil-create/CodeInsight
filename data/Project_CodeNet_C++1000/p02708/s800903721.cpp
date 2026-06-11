#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(long long i = a; i < (b); ++i)
typedef long long ll;

int main() {
    long long N, K, MOD = 1000000007;
    cin >> N >> K;
    long long ANS = 0;
    for (long long k = K; k <= N + 1; k++) {
        long long int MIN = ( k - 1) * k / 2;
        long long int MAX = ( N + ( N - k + 1 ) ) * k / 2;
        ANS += MAX - MIN + 1;
        ANS %= MOD;
    }
    cout << ANS << endl;
    return 0;
}
