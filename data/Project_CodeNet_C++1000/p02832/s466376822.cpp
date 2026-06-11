#ifdef _MSC_VER
#include <__msvc_all_public_headers.hpp>
#undef min
#undef max
#else
#define NDEBUG
#include <bits/stdc++.h>
#endif

using namespace std;
using large = long long;

static int N;
static array<vector<int>, 200'005> Pos;

static int solve() {
    int xmax = -1;
    int pos = 0;
    for (int x = 1; x <= N; ++x) {
        auto itr = upper_bound(Pos[x].begin(), Pos[x].end(), pos);
        if (itr == Pos[x].end())
            break;
        xmax = x;
        pos = *itr;
    }
    return (xmax < 0 ? -1 : N - xmax);
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        int Ai;
        cin >> Ai;
        Pos[Ai].push_back(i);
    }

    cout << solve() << endl;
    return 0;
}
