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

const int MOD = 1000000007;

int exp(int a, int x)
{
    lint ret = 1, tmp = a % MOD;
    while (x > 0) {
        if (x % 2 == 1)
            ret = ret * tmp % MOD;
        x = x / 2;
        tmp = tmp * tmp % MOD;
    }

    return (int) ret;
}

int inv(int a)
{
    return exp(a, MOD - 2);
}

int F(int x, int y)
{
    if ((x + y) % 3 != 0)
        return 0;

    if (x > y)
        swap(x, y);

    // x <= y;
    if (y > 2 * x)
        return 0;

    int row = (x + y) / 3;
    int col = x - row;
    // 0 <= col <= row
    // answer is nCr(row, col) % MOD
    int numer = 1, denom = 1;
    FOR(i, 1, row + 1)
        numer = (int)(numer * 1LL * i % MOD);

    FOR(i, 1, col + 1)
        denom = (int)(denom * 1LL * i % MOD);

    FOR(i, 1, row - col + 1)
        denom = (int)(denom * 1LL * i % MOD);

    return (int)(numer * 1LL * inv(denom) % MOD);
}

int main(int argc, char **argv)
{
    io_init();

    // Actual program code starts here.
    int X, Y;
    cin >> X >> Y;
    cout << F(X, Y) << endl;
    return 0;
};