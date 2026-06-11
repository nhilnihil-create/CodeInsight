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
    cin >> N;
    VEC(VEC(int)) PrefOrder(N);
    // VEC(VEC(int)) Order(N, VEC(int)(N));
    FOR(i, 0, N) {
        FOR(j, 0, N - 1) {
            int t;
            cin >> t;
            PrefOrder[i].push_back(t - 1);
            // Order[i][t - 1] = j;
        }
    }

    int days = 0, matchups = 0;
    VEC(Pii) pairings;
    VEC(int) Progress(N, 0);

    FOR(i, 0, N) {
        int j = PrefOrder[i][0];
        if (PrefOrder[j][0] == i && i < j)
            pairings.push_back(Pii(i, j));
    }

    while (matchups < N * (N - 1)) {
        days++;
        if (pairings.empty()) {
            cout << -1 << endl;
            return 0;
        }

        set<int> seen;
        VEC(Pii) newPairings;

        for (auto& pr: pairings) {
            int i = pr.first, j = pr.second;
            Progress[i]++; Progress[j]++;
            matchups += 2;
        }

        for (auto& pr : pairings) {
            int i = pr.first, j = pr.second;
            // int ix = Order[i][j] + 1, jx = Order[j][i] + 1;
            int ix = Progress[i], jx = Progress[j];

            if (ix < N - 1) {
                int t = PrefOrder[i][ix];
                if (!seen.count(t) && Progress[t] < N - 1) {
                    int q = PrefOrder[t][Progress[t]];
                    if (Progress[q] < N - 1 && PrefOrder[q][Progress[q]] == t) {
                        seen.insert(t);
                        seen.insert(q);
                        if (t > q)
                            swap(t, q);
                        newPairings.push_back(Pii(t, q));
                    }
                }
            }
            
            if (jx < N - 1) {
                int t = PrefOrder[j][jx];
                if (!seen.count(t) && Progress[t] < N - 1) {
                    int q = PrefOrder[t][Progress[t]];
                    if (Progress[q] < N - 1 && PrefOrder[q][Progress[q]] == t) {
                        seen.insert(t);
                        seen.insert(q);
                        if (t > q)
                            swap(t, q);
                        newPairings.push_back(Pii(t, q));
                    }
                }
            }
        }

        pairings = newPairings;
    }

    cout << days << endl;
    return 0;
};
