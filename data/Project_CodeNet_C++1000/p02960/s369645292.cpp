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
    string S;
    cin >> S;
    reverse(ALL(S));

    // 1, 10, 9, 12, 3, 4 ....
    VEC(int) Offset(6, 0), Marks(6, 0);
    FOR(i, 0, S.size())
        if (S[i] == '?')
            Marks[i % 6]++;
        else
            Offset[i % 6] = (Offset[i % 6] + S[i] - '0') % 13;

    const int MOD = 1000000007;
    VEC(VEC(int)) Dp(20011, VEC(int)(13, 0));
    Dp[0][0] = 1;
    FOR(i, 0, 20009) {
        FOR(rem, 0, 13) {
            FOR(d, 0, 10) {
                int& tmp = Dp[i + 1][(rem + d) % 13];
                tmp += Dp[i][rem];
                tmp %= MOD;
            }
        }
    }

    VEC(int) Coeffs {1, 10, 9, 12, 3, 4};
    VEC(int) Table[13][13];
    FOR(a, 0, 13)
        FOR(b, 0, 13)
            Table[a * b % 13][a].push_back(b);

    int ret = 0;

    FOR(r0, 0, 13)
        FOR(r1, 0, 13)
            FOR(r2, 0, 13)
                FOR(r3, 0, 13)
                    FOR(r4, 0, 13)
                        FOR(r5, 0, 13)
                            {
                                VEC(int) R{r0, r1, r2, r3, r4, r5};
                                int rem = 0;
                                FOR(i, 0, 6)
                                    rem = (rem + Coeffs[i] * (Offset[i] + R[i])) % 13;
                                // rem + (Offset[5] + r5) * Coeff[5] == 5
                                // (r5 + off5) * cff[5] = 5 - rem
                                if (rem == 5) {
                                    lint prod = 1;
                                    FOR(i, 0, 6)
                                        prod = prod * Dp[Marks[i]][R[i]] % MOD;

                                    ret = (ret + prod) % MOD;
                                }
                            }

    cout << ret << endl;
    return 0;
};
