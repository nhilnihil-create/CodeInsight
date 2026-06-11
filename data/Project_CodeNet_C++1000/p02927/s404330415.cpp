#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int m, d;
    cin >> m >> d;
    int cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            if (j / 10 <= 1 || j % 10 <= 1)
            {
                continue;
            }
            if (i == (j / 10) * (j % 10))
            {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}