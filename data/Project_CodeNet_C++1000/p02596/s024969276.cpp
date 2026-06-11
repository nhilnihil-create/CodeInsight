#include <iostream>
#include <algorithm>
#include <deque>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>
#include <cmath>
#define rep0(i, n) for (i = 0; i < n; i++)
#define rep(s, i, n) for (i = s; i < n; i++)
using namespace std;

int main()
{
    int K;
    cin >> K;

    int i, r = 7%K;
    rep0(i, K)
    {
        if (r == 0)
        {
            cout << i + 1 << endl;
            return 0;
        }
        r = (r * 10 + 7) % K;
    }

    cout << -1 << endl;
    return 0;
}