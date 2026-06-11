#include <iostream>
#include <queue>
#define int long long

using namespace std;

signed main()
{

    int k;
    cin >> k;
    queue<int> q;
    for (int i = 1; i <= 9; i++)
        q.push(i);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        k--;
        if (k == 0)
        {
            cout << x << '\n';
            break;
        }
        int t = x % 10;
        for (int y = t - 1; y <= t + 1; y++)
        {
            if (y < 0)
                continue;
            if (y > 9)
                break;
            q.push(x * 10 + y);
        }
    }

    return 0;
}