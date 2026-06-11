#include <iostream>
#include <sstream>
#include <stack>
#include <iomanip>
#include <numeric>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>

#define BEGIN(x) x.begin()
#define END(x) x.end()
#define ALL(x) BEGIN(x), END(x)
#define PAIR make_pair
#define VEC(type) vector<type >
#define endl '\n'

#define FOR(i, A, B) for(auto i = (A);i != (B); i++)
#define FORD(i, A, B) for(auto i = (A);i != (B); i--)

#define READRANGE(begin, end) FOR(it, begin, end) cin >> *it
#define READVEC(V) READRANGE(BEGIN(V), END(V))

using namespace std;

typedef long long lint;
typedef pair<int, int> Pii;
typedef pair<int, lint> Pil;
typedef pair<lint, lint> Pll;
typedef pair<lint, int> Pli;

// ---- BEGIN LIBRARY CODE ----
// ---- END LIBRARY CODE ----
void io_init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
};

int main(int argc, char **argv)
{
    io_init();

    // Actual program code starts here.
    const int MOD = 1000000007;

    VEC(VEC(int)) F(2005, VEC(int)(2005, 0));
    F[0][0] = 1;
    FOR(n, 1, 2005) {
        FOR(k, 1, 2005) {
            F[n][k] = F[n - 1][k - 1];
            F[n][k] += F[n - 1][k];
            if (F[n][k] >= MOD)
                F[n][k] -= MOD;
        }
    }

    int N, K;
    cin >> N >> K;
    FOR(k, 1, K + 1) {
        cout << (int)((F[K][k] * 1LL * F[N - K + 2][k + 1]) % MOD);
        cout << "\n";
    }

    return 0;
};
