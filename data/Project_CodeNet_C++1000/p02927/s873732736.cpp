#include <bits/stdc++.h>

using namespace std;

int m, d;

int tich(int x)
{
    return (x/10)*(x%10);
}

int main()
{
    ios_base:: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> d;
    int res = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 10; j <= d; j++)
        {
            if(j / 10 >= 2 && j % 10 >= 2&& tich(j) == i)
            {
                res++;
            }
        }
    }
    cout << res;
    return 0;
}
