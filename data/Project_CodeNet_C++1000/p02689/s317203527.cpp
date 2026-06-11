#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cassert>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <list>
#include <forward_list>
#include <array>
#include <cstring>
#include <cmath>
#include <tuple>
#include <complex>
#include <bitset>
#include <climits>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using LD = long double;
using pii = pair<int, int>;
using pll = pair<LL, LL>;
using pld = pair<LD, LD>;
const int MAX_N = 1e5;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;
    vector<int> elev(N + 1);
    for (int i = 1; i <= N; ++i)
    {
        cin >> elev[i];
    }

    vector<int> max_adj_of(N + 1);
    while (M--)
    {
        int i, j;
        cin >> i >> j;

        max_adj_of[i] = max(max_adj_of[i], elev[j]);
        max_adj_of[j] = max(max_adj_of[j], elev[i]);
    }

    int ans = 0;
    for (int obs = 1; obs <= N; ++obs)
    {
        ans += elev[obs] > max_adj_of[obs];
    }

    cout << ans;
}
