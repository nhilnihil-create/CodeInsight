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
    cin >> N;

    vector<int> nr_subords(N + 1);
    for (int i = 2; i <= N; ++i)
    {
        int A;
        cin >> A;

        ++nr_subords[A];
    }

    for (int i = 1; i <= N; ++i)
    {
        cout << nr_subords[i] << "\n";
    }
}
