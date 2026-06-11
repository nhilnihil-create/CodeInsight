#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <queue>
#include <stack>
#include <bitset>
#include <set>
#include <chrono>
#include <string>

using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    n--;

    vector<int> val(n);

    bool is_one = false;

    for (int i = 0; i < n; ++i)
    {
        val[i] = abs(s[i] - s[i + 1]);
        is_one |= val[i] == 1;
    }

    if (n == 1)
    {
        cout << val[0] << endl;
        return 0;
    }

    int x = 0;

    for (int i = 0; i < n; ++i)
    {
        if (is_one)
            val[i] &= 1;
        else
            val[i] >>= 1;

        if (val[i] == 1 && (i & (n - 1)) == i)
        {
            x ^= 1;
        }
    }

    if (!is_one)
        x *= 2;

    cout << x << endl;

    return 0;
}