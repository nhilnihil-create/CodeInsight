#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define LINF 1000000000000000000
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef pair<int, int> P;
typedef pair<long long, long long> LLP;

long long f(long long A, long long B, long long x) {
    return (A * x / B) - A * (x / B);
}

int main() {

    long long A, B, N;
    cin >> A >> B >> N;
    cout << f(A, B, min(B - 1, N)) << endl;
    return 0;
}