#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1001001001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<char>> grid(h, vector<char>(w));
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> grid[i][j];
        }
    }
    // 横方向の和をとる
    vector<vector<int>> yoko(h, vector<int>(w));
    for (int i = 0; i < h; i++)
    {
        int st = 0;
        for (int j = 0; j < w; j++)
        {
            if (grid[i][j] == '#')
            {
                for (int k = st; k < j; k++)
                {
                    yoko[i][k] = j - st;
                }
                yoko[i][j] = 0;
                st = j + 1;
            }
        }
        for (int k = st; k < w; k++)
        {
            yoko[i][k] = w - st;
        }
    }
    // 縦方向の和をとる
    vector<vector<int>> tate(h, vector<int>(w));
    for (int j = 0; j < w; j++)
    {
        int st = 0;
        for (int i = 0; i < h; i++)
        {
            if (grid[i][j] == '#')
            {
                for (int k = st; k < i; k++)
                {
                    tate[k][j] = i - st;
                }
                tate[i][j] = 0;
                st = i + 1;
            }
        }
        for (int k = st; k < h; k++)
        {
            tate[k][j] = h - st;
        }
    }
    // for (auto y : yoko)
    // {
    //     print(y);
    // }
    // cout << "===" << endl;
    // for (auto t : tate)
    // {
    //     print(t);
    // }
    int maxi = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            maxi = max(maxi, tate[i][j] + yoko[i][j]);
        }
    }
    if (maxi != 0)
    {
        cout << maxi - 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }

    return 0;
}

// Use For Debug
template <typename T>
void print(T const &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << v[i];
    }
    cout << endl;
}