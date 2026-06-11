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

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= (M + 1) / 2; i++) {
        int k = (M + 1) / 2 - i;
        k = 2 * k + 1;
        printf("%d %d\n", i, i + k);
    }

    int start_even = 1 + 2 * ((M + 1) / 2 - 1) + 1;
    for (int i = 1; i <= M / 2; i++) {
        int k = M / 2 - i;
        k = 2 * (k + 1);
        printf("%d %d\n", start_even + i, start_even + i + k);
    }
    
    return 0;
}