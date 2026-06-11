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


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    LL K;
    cin >> N >> K;

    vector<int> nrs(N + 1);
    for (int i = 1; i <= N; ++i)
    {
        cin >> nrs[i];
    }

    vector<int> path(N + 1), last_idx(N + 1);
    for (int cur_nr = nrs[1], i = 1; ; ++i)
    {
        if (i == K)
        {
            cout << cur_nr;
            return 0;
        }
        if (last_idx[cur_nr])
        {
            int mod = i - last_idx[cur_nr];
            cout << path[last_idx[cur_nr] + (mod - last_idx[cur_nr] % mod + K % mod) % mod];
            return 0;
        }

        path[i] = cur_nr;
        last_idx[cur_nr] = i;
        cur_nr = nrs[cur_nr];
    }
}
