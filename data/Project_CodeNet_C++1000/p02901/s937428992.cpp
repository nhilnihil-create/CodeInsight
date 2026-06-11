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

int dp[1024][1 << 12];

int main(int argc, char **argv)
{
    io_init();

    // Actual program code starts here.
    int N, M;
    cin >> N >> M;
    VEC(int) KeyMask(M, 0), KeyCost(M);
    FOR(i, 0, M) {
        int k;
        cin >> KeyCost[i] >> k;
        while (k--) {
            int box;
            cin >> box;
            KeyMask[i] |= 1 << (box - 1);
        }
    }

    FOR(i, 0, M + 1)
        FOR(mask, 0, 1 << N)
            dp[i][mask] = 1 << 29;

    dp[0][0] = 0;
    FOR(i, 0, M) {
        FOR(mask, 0, 1 << N) {
            dp[i + 1][mask] = min(dp[i + 1][mask], dp[i][mask]);
            int& v = dp[i + 1][mask | KeyMask[i]];
            v = min(v, dp[i][mask] + KeyCost[i]);
        }
    }

    if (dp[M][(1 << N) - 1] >= 1 << 29)
        cout << -1;
    else
        cout << dp[M][(1 << N) - 1];
    cout << endl;

    return 0;
};