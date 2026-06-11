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
const int M = 1e9 + 7;


inline int my_mod(const int a, const int m = M)
{
    return (a % m + m) % m;
}


int comp(const int sum_so_far, const int cur_nr)
{
    return my_mod(sum_so_far + cur_nr);
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    vector<int> nrs(N + 1), pref(N + 1), suff(N + 1);
    iota(begin(nrs), end(nrs), 0);
    partial_sum(begin(nrs), end(nrs), begin(pref), comp);  // prefix sum.
    partial_sum(nrs.rbegin(), nrs.rend(), begin(suff), comp);  // suffix sum.
    /*for (int i = 0; i <= N; ++i)
    {
        cout << "pref[" << i << "]: " << pref[i] << endl;
    }
    cerr << endl;
    for (int i = 0; i <= N; ++i)
    {
        cout << "suff[" << i << "]: " << suff[i] << endl;
    }
*/
    int res = 0;
    for (int i = K; i <= N + 1; ++i)
    {
        res = my_mod(res + my_mod(suff[i - 1] - pref[i - 1] + 1));
    }

    cout << res;
}
