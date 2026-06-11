#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
    int N, M; cin >> N >> M;
    if (M % 2 == 0)
    {
        for (int i = 0; i < M / 2; ++i)
        {
            cout << i + 1 << ' ' << M + 1 - i << endl;
        }
        for (int i = 0; i < M / 2; ++i)
        {
            cout << M + 2 + i << ' ' << 2 * M + 1 - i << endl;
        }
    }
    else
    {
        for (int i = 0; i < (M - 1) / 2; ++i)
        {
            cout << i + 1 << ' ' << M - i << endl;
        }
        for (int i = 0; i < (M + 1) / 2; ++i)
        {
            cout << M + i + 1 << ' ' << 2 * M + 1 - i << endl;
        }
    }
}