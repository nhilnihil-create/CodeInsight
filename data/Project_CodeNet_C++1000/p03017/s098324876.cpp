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
#include <assert.h>

using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    string s;
    cin >> s;

    s = "." + s;

    auto exist = [&](int x, int y, int k, char c) {
        int t = 0;
        for (int i = x; i <= y; ++i)
        {
            if (s[i] == c)
                ++t;
            else
                t = 0;
            if (t == k)
                return true;
        }
        return false;
    };

    if (exist(a, c, 2, '#') || exist(b, d, 2, '#'))
    {
        cout << "No" << endl;
        return 0;
    }

    if (c < d)
    {
        cout << "Yes" << endl;
        return 0;
    }

    if (!exist(b - 1, d + 1, 3, '.'))
    {
        cout << "No" << endl;
        return 0;
    }
    else
    {
        cout << "Yes" << endl;
    }

    return 0;
}