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
    int N, K;
    cin >> N >> K;
    VEC(int) A(N);
    READVEC(A);

    int S = 0;
    FOR(i, 0, N)
        S += A[i];

    auto need = [&A](int g) {

        lint ret = 0;
        int halves = 0;
        VEC(int) rems;
        for (int a : A) {
                rems.push_back(a % g);
        }

        sort(ALL(rems));
        VEC(lint) Suffix(1 + rems.size(), 0);
        for (int i = rems.size() - 1;i >= 0; i--) {
            Suffix[i] = Suffix[i + 1] + (g - rems[i]);
        }

        lint add = 0, mn = 1LL << 60;
        for (int i = 0;i + 1 <= rems.size(); i++) {
            add += rems[i];
            mn = min(mn, max(add, Suffix[i + 1]));
        }

        return ret + mn;
    };

    int ret = 0;
    for (int g = 1;g <= S / g; g++)
        if (S % g == 0) {

            if (need(g) <= K)
                ret = max(ret, g);
            if (need(S / g) <= K)
                ret = max(ret, S / g);
        }

    cout << ret << endl;
    return 0;
};
