#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>

using namespace std;


int c[6];
int h, w, k;

int f(int m, int n)
{
    int y = 0;
    for (int i = 0; i < h; i++)
    {
        if ((m >> i) & 1)
        {
            int x = c[i] & n;
            for (int j = 0; j < w; j++)
            {
                if ((x >> j) & 1)
                {
                    y++;
                }
            }
        }
        else
        {
            continue;
        }
    }
    return (k == y);
}

int main()
{
    cin >> h >> w >> k;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            char ch;
            cin >> ch;
            c[i] = (c[i] << 1) | (ch == '.' ? 0 : 1);
        }
    }
    int a = 0;
    for (int i = 0; i < (1 << h); i++)
    {
        for (int j = 0; j < (1 << w); j++)
        {
            a += f(i, j);
        }
    }
    cout << a << endl;
    return 0;
}