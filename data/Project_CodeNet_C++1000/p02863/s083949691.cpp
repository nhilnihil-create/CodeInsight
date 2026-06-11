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

int T, dp[3005][3005];
VEC(int) A, B;

int f(int t, int i)
{
    if (i == A.size() || t >= T)
        return 0;

    int& ans = dp[t][i];
    if (ans >= 0)
        return ans;

    ans = f(t, i + 1);
    ans = max(ans, B[i] + f(t + A[i], i + 1));
    return ans;
};

int main(int argc, char **argv)
{
    io_init();

    // Actual program code starts here.
    int N;
    cin >> N >> T;
    A.resize(N);
    B.resize(N);
    VEC(Pii) dishes(N);
    FOR(i, 0, N)
        cin >> dishes[i].first >> dishes[i].second;
    sort(ALL(dishes));

    FOR(i, 0, N) {
        A[i] = dishes[i].first;
        B[i] = dishes[i].second;
    }

    memset(dp, -1, sizeof dp);
    cout << f(0, 0) << endl;
    return 0;
};