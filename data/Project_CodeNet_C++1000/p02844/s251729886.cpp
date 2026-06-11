#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using VVI = vector<vector<int>>;
const int INF = 1001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

bool dp[30009][4][1009];
string s;
int n;

int main()
{
    cin >> n >> s;
    dp[0][0][0] = true;

    for (int i = 0; i < n; i++) // 桁数
    {
        for (int j = 0; j <= 3; j++)
        {
            for (int k = 0; k < 1000; k++)
            {
                if (dp[i][j][k] == false)
                {
                    continue;
                }
                dp[i + 1][j][k] = true;
                if (j <= 2)
                {
                    dp[i + 1][j + 1][k * 10 + (s[i] - '0')] = true;
                }
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < 1000; i++)
    {
        if (dp[n][3][i] == true)
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}

// Use For Debug
template <typename T>
void print(T const &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << " ";
        cout << v[i];
    }
    cout << endl;
}