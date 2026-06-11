#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int a, b, res = INT_MAX;
    cin >> a >> b;

    for(int i = 1; i <= 10000; ++i)
    {
        int x = i * 0.08;
        int y = i * 0.1;

        if(x == a && y == b)
            res = min(res, i);
    }

    cout << (res == INT_MAX ? -1 : res) << "\n";
    return 0;
}