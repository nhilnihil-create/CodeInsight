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

const int MOD = 1000000007, MAXN = 100100;
int dp[MAXN][2][2];
string L;

int f(int i, int ls, int cp)
{
    if (i == L.size()) {
        return 1;
    }

    int& ans = dp[i][ls][cp];
    if (ans >= 0)
        return ans;

    ans = 0;
    FOR(a, 0, 2)
        FOR(b, 0, 2) {
            if (a == 1 && b == 1)
                continue;
            if (ls == 0 && (a + b) == 1 && L[i] == '0')
                continue;

            ans += f(i + 1, ls || (L[i] == '1' && a + b == 0), 
                        cp || (a < b));
            if (ans >= MOD)
                ans -= MOD;
        }

    return ans;
}

int main(int argc, char **argv)
{
    io_init();

    // Actual program code starts here.
    cin >> L;
    memset(dp, -1, sizeof dp);

    int ret = f(0, 0, 0);
    cout << ret << endl;
    return 0;
};
