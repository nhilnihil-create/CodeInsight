#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

int main(void)
{
    int n, d;
    cin >> n >> d;

    vector<vector<int>> map(n, vector<int>(d));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < d; j++)
        {
            cin >> map[i][j];
        }
    }

    // int sum;
    // int ans = 0;
    // int num;
    // for (int i = 0; i < n - 1; i++)
    // {
    //     sum = 0;
    //     for (int j = 0; j < d; j++)
    //     {
    //         sum += pow(abs((map[i][j]) - map[i + 1][j]), 2);
    //     }
    //     num = sqrt(sum);
    //     if (num * num == sum)
    //     {
    //         ans++;
    //     }
    // }

    // sum = 0;
    // for (int i = 0; i < d; i++)
    // {
    //     sum += pow(abs(map[n - 1][i] - map[0][i]), 2);
    // }
    // num = sqrt(sum);
    // if (num * num == sum)
    // {
    //     ans++;
    // }

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int norm = 0;
            for (int k = 0; k < d; ++k)
            {
                int diff = abs(map[i][k] - map[j][k]);
                norm += diff * diff;
            }
            bool flag = false;
            for (int k = 0; k <= norm; ++k)
            {
                if (k * k == norm)
                {
                    flag = true;
                }
            }
            if (flag)
                ++ans;
        }
    }
    cout << ans << endl;
    return (0);
}