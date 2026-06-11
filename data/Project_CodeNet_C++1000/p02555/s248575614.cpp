#include <bits/stdc++.h>
using namespace std;

long long int ncr[3001][1001];
int main()
{
    long long int s;
    cin >> s;
    long long int mod = 1e9 + 7;
    ncr[0][0]=1;
    for (int j = 0; j < 1001; j++)
    {
        for (int i = 1; i < 3001; i++)
        {
            if (i < j)
                continue;
            else if (i == j)
                ncr[i][j] = 1;
            else if (j == 0)
            {
                ncr[i][j] = 1;
            }
            else if (j == 1)
            {
                ncr[i][j] = i;
            }
            else
            {   
                ncr[i][j] = (ncr[i-1][j] + ncr[i - 1][j - 1]) % mod;
                // cout<<ncr[i][j]<<" ";
            }
        }
        // cout<<endl;
    }
    int m = s / 3;
    long long int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ans = (ans + ncr[s - 3 * i + i - 1][i - 1]) % mod;
    }
    cout << (ans + mod) % mod << endl;
}