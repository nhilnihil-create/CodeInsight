#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int minSequenceSize(string x, string y)
{
    int x_len = x.size();
    int y_len = y.size();
    int map[x_len][y_len] = {};

    for (int i = 0; i < x_len; i++)
    {
        for (int j = 0; j < y_len; j++)
        {
            if (i == 0)
            {
                map[0][j] = 0;
                continue;
            }
            if (j == 0)
            {
                map[i][0] = 0;
                continue;
            }

            if (x[i] == y[j])
            {
                map[i][j] = map[i - 1][j - 1] + 1;
                continue;
            }

            if (x[i] != y[j])
            {
                map[i][j] = max(map[i - 1][j], map[i][j - 1]);
                continue;
            }
        }
    }
    return map[x_len - 1][y_len - 1];
}

int main()
{
    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        string x, y;
        cin >> x >> y;

        x = " " + x;
        y = " " + y;
        int ans = minSequenceSize(x, y);
        cout << ans << endl;
    }
}
