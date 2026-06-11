// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=1188811#1

#include <iostream>
#include <string>

using namespace std;

// 何文字共通しているかの計算
int minStepSize(string s1, string s2)
{
    s1 = " " + s1;
    s2 = " " + s2;
    int rows = s1.size();
    int cols = s2.size();
    int map[rows][cols] = {};

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i == 0)
            {
                map[0][j] = j;
                continue;
            }
            else if (j == 0)
            {
                map[i][0] = i;
                continue;
            }

            if (s1[i] == s2[j])
            {
                map[i][j] = min(map[i - 1][j] + 1, min(map[i][j - 1] + 1, map[i - 1][j - 1]));
            }
            else
            {
                map[i][j] = min(map[i - 1][j] + 1, min(map[i][j - 1] + 1, map[i - 1][j - 1] + 1));
            }
        }
    }

    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < cols; j++)
    //     {
    //         printf("map[%d][%d] = %d\n", i, j, map[i][j]);
    //     }
    // }
    // printf("map.cols() = %d\nmap.rows() = %d\n", rows, cols);
    return map[rows - 1][cols - 1];
}

int sameSizeString(string s1, string s2)
{
    int ans = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] == s2[i])
        {
            ans++;
        }
    }
    return ans;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int common = minStepSize(s1, s2);

    cout << common << endl;
}
