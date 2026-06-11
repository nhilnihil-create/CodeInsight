#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <cmath>
#include <cstdio>

using namespace std;

typedef long long ll;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)

int main(int argc, char **argv)
{
    int N, M;
    cin >> N >> M;
    int p1, p2;
    p1 = 1;
    p2 = N;
    bool f[N];
    REP(i, N) f[i] = false;

    REP(i, M) {
        cout << p1 << " " << p2 << endl;
        f[p2 - p1] = true;
        f[p1 + N - p2] = true;
        p1++;
        p2--;
        while (true) {
            if (f[p2 - p1] == true || f[p1 + N - p2] == true || p2 - p1 == p1 + N - p2) {
                p2--;
            }
            else {
                break;
            }
        }
    }

    return 0;
}
