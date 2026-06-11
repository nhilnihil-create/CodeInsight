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
    int N;
    lint K;
    cin >> N >> K;
    VEC(lint) A(N), F(N);
    READVEC(A);
    READVEC(F);

    sort(ALL(A), greater<lint>());
    sort(ALL(F));

    auto check = [&](lint x) {
        lint ret = 0;
        FOR(i, 0, N) {
            // (Ai - t) * F[i] <= x
            // t >= Ai - x / F[i]
            lint need = max(A[i] - x / F[i], 0LL);
            ret += need;
        }

        return ret;
    };

    lint lo = 0, hi = 1LL << 60;
    while (hi - lo > 1) {
        lint md = lo + (hi - lo) / 2;
        if (check(md) <= K)
            hi = md;
        else
            lo = md + 1;
    }

    if (check(lo) > K)
        lo = hi;

    cout << lo << endl;
    return 0;
};
