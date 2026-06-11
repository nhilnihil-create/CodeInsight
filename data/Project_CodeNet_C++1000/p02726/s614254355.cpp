// 
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <bitset>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define REP(i, n) for(size_t i = 0; i < (n); ++i)

int main()
{
    int N, X, Y;
    cin >> N >> X >> Y;
    vector<int> res(N, 0);
    for (int i = 1; i <= N - 1; ++i)
    {
        for (int j = i + 1; j <= N; ++j)
        {
            int d1 = j - i;
            int d2 = abs(j - Y) + abs(X - i) + 1;
            int d = min(d1, d2);
            ++res[d];
        }
    }
    for (int k = 1; k <= N - 1; ++k)
    {
        cout << res[k] << endl;
    }
    return 0;
}
