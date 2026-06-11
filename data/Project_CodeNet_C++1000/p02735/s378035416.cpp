#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>

using namespace std;

int h, w;
vector<vector<char>> s;
vector<vector<int>> score;

int main(int argc, char const *argv[])
{
    cin >> h >> w;
    s = vector<vector<char>>(h, vector<char>(w));
    score = vector<vector<int>>(h, vector<int>(w, 1001001001));

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> s.at(i).at(j);
        }
    }

    if (s[0][0] == '.')
    {
        score[0][0] = 0;
    }
    else
    {
        score[0][0] = 1;
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (s[i][j] == '.')
            {
                if (i == h - 1 && j == w - 1)
                {
                    break;
                }
                if (i == h - 1)
                {
                    if (s[i][j + 1] == '#')
                        score[i][j + 1] = min(score[i][j] + 1, score[i][j + 1]);
                    else if (s[i][j + 1] == '.')
                        score[i][j + 1] = min(score[i][j+1], score[i][j]);
                    continue;
                }
                else if (j == w - 1)
                {
                    if (s[i + 1][j] == '#')
                        score[i + 1][j] = min(score[i][j] + 1, score[i + 1][j]);
                    else if (s[i + 1][j] == '.')
                        score[i + 1][j] = min(score[i+1][j], score[i][j]);
                    continue;
                }
                if (s[i + 1][j] == '#') //下
                    score[i + 1][j] = min(score[i][j] + 1, score[i + 1][j]);
                else if (s[i + 1][j] == '.')
                    score[i + 1][j] = min(score[i+1][j],score[i][j]);

                if (s[i][j + 1] == '#') //右
                    score[i][j + 1] = min(score[i][j] + 1, score[i][j + 1]);
                else if (s[i][j + 1] == '.')
                    score[i][j + 1] = min(score[i][j+1] ,score[i][j]);
            }
            else
            {
                if (i == h - 1 && j == w - 1)
                {
                    break;
                }
                if (i == h - 1)
                {
                    score[i][j + 1] = min(score[i][j], score[i][j+1]);
                    continue;
                }
                else if (j == w - 1)
                {
                    score[i + 1][j] = min(score[i+1][j], score[i][j]);
                    continue;
                }

                score[i + 1][j] = min(score[i+1][j], score[i][j]);
                score[i][j + 1] = min(score[i][j+1], score[i][j]);
            }
        }
    }

    cout << score[h - 1][w - 1] << endl;

    /*
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cout << score[i][j] << " ";
        }
        cout << endl;
    }
    */

    return 0;
}
