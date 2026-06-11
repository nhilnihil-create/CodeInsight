#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    string S;
    cin >> N >> M >> S;

    stack<int> res;
    int pos = N;
    while (pos > 0)
    {
        int next = -1;
        for (int d = M; d > 0; d--)
        {
            if (pos - d < 0)
            {
                continue;
            }
            if (S.at(pos - d) == '0')
            {
                next = pos - d;
                res.push(d);
                break;
            }
        }
        if (next < 0)
        {
            cout << -1 << endl;
            return 0;
        }
        pos = next;
    }
    while (res.size())
    {
        cout << res.top() << " ";
        res.pop();
    }
    cout << endl;
}