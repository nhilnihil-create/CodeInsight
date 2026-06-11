#include <iostream>
#include <vector>
using namespace std;

void gcd(vector<vector<int>> &g, int k)
{
    int c;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            c = j;
            while (i % c > 0 || j % c > 0) {c--;}
            g[i-1][j-1] = c; g[j-1][i-1] = c;
        }
    }
}

int main(void)
{
    int k; cin >> k;
    vector<vector<int>> g(k, vector<int>(k)); gcd(g, k);
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            for (int l = 0; l < k; l++) ans += g[i][g[j][l]-1];
        }
    }
    cout << ans << endl;
}