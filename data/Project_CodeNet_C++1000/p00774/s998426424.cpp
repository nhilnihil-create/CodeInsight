#include <iostream>
#include <stdio.h>

using namespace std;

int remove(int row[5])
{
    int i;
    int start_num = row[0];
    int len = 1;
    for (i = 1; i < 5; i++)
    {
        if (row[i] == start_num) { len++; }
        else {
            if (len >= 3) { break; }
            else { start_num = row[i]; len = 1; }
        }
    }
    int pt = 0, ct = 0;
    if (len >= 3) {
        pt = row[i - len];
        while (len-- > 0)
        {
            row[i - len - 1] = 0;
            ct++;
        }
        pt *= ct;
    }
    return pt;
}

void drop(int row[10][5], int h)
{
    for (int x = 0; x < 5; x++)
    {
        for (int y = h - 1; y > 0; )
        {
            if (row[y][x] == 0)
            {
                bool flag = false;
                for (int i = y; i > 0; i--)
                {
                    row[i][x] = row[i - 1][x];
                    if (row[i][x] != 0)
                    {
                        flag = true;
                    }
                }
                row[0][x] = 0;
                if (flag == false)
                {
                    break;
                }
            }
            else
            {
                y--;
            }
        }
    }
}

int calc(int row[10][5], int h)
{
    int pt = 0;

    while (true)
    {
        int tmp = 0;
        for (int i = 0; i < h; i++)
        {
            tmp += remove(row[i]);
        }
        drop(row, h);
        if (tmp == 0)
        {
            break;
        }
        pt += tmp;
    }
    return pt;
}

int main(void)
{
    int H;

    while (cin >> H, H)
    {
        int row[10][5];
        for (int i = 0; i < H; i++)
        {
            cin >> row[i][0] >> row[i][1] >> row[i][2] >> row[i][3] >> row[i][4];
        }

        int ans = calc(row, H);
        cout << ans << endl;
    }

    return 0;
}