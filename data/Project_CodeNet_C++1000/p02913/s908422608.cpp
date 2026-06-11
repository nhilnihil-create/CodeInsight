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

vector<int> kmpFailureFunc(const string& S)
{
    const int n = S.size();
    vector<int> F(n + 1, -1);
    F[1] = 0;
    for (int i = 2;i <= n; i++) {
        char c = S[i - 1];
        int l = F[i - 1];
        while (l >= 0 && S[l] != c)
            l = F[l];
        F[i] = l + 1;
    }

    return F;
}

bool check(string& S, int l)
{
    if (l == 0)
        return true;

    const int N = S.size();
    FOR(i, 0, N - l + 1) {
        string key = S.substr(i, l);
        VEC(int) F = kmpFailureFunc(key);

        int s = 0;
        FOR(j, i + l, N) {
            char c = S[j];
            while (s >= 0 && key[s] != c)
                s = F[s];
            s++;

            if (s == l)
                return true;
        }
    }

    return false;
};

int main(int argc, char **argv)
{
    io_init();

    // Actual program code starts here.
    int N;
    string S;
    cin >> N >> S;

    int lo = 0, hi = N / 2;
    while (hi - lo > 1) {
        int md = (lo + hi) / 2;
        if (check(S, md))
            lo = md;
        else
            hi = md - 1;
    }

    if (!check(S, hi))
        hi = lo;
    cout << hi << endl;
    return 0;
};