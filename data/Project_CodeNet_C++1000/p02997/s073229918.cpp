#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <utility>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <numeric>

using namespace std;

typedef uint64_t u64;
typedef int64_t s64;
typedef uint32_t u32;
typedef int32_t s32;
typedef vector<s32> vs32;
typedef vector<u32> vu32;
typedef vector<s64> vs64;
typedef vector<u64> vu64;

const double PI=3.14159265358979323846;

#define MAX(x, y) ((x) < (y) ? (y) : (x))
#define MIN(x, y) ((x) > (y) ? (y) : (x))

#define rep(i, N) for(int i = 0; i < N; ++i)

#define CEIL(x, y) (((x) + (y) - 1) / (y))
#define MOD 1000000007ULL

#define IN(l, r, x) ((l) <= (x) && (x) < (r))

// ABC 146 F

using P = pair<int, int>;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    int num = (n - 2) * (n - 1) / 2;
    if (num < k)
    {
        cout << "-1\n";
        return 0;
    }

    vector< P > edge;
    rep (i, n - 1)
    {
        edge.emplace_back(i + 1, n);
    }

    int start = 1;
    int a = 2;
    while (num > k)
    {
        if (a == n)
        {
            a = ++start + 1;
        }
        edge.emplace_back(start, a++);
        --num;
    }

    cout << edge.size() << "\n";
    for (auto& e : edge)
    {
        cout << e.first << " " << e.second << "\n";
    }
    return 0;
}

