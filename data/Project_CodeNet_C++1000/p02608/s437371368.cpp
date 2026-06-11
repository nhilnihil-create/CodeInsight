#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> ans(n);
    for (int i = 1; i < 100; i++)
    {
        for (int j = 1; j < 100; j++)
        {
            for (int k = 1; k < 100; k++)
            {
                int t = i * i + j * j + k * k + i * j + i * k + j * k;
                if (t <= 10000)
                    ans[t - 1]++;
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << endl;
}
