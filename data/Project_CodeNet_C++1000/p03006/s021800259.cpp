#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    pair<int,int> pai[n];
    for(int i = 0;i < n;i++)
    {
        cin >> pai[i].first >> pai[i].second;
    }
    if(n == 1)
    {
        cout << "1\n";
        return 0;
    }
    int ans = INT_MAX;
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            if(i == j)
            {
                continue;
            }
            int p = pai[i].first - pai[j].first;
            int q = pai[i].second - pai[j].second;
            int temp = 0;
            for(int k = 0;k < n;k++)
            {
                for(int l = 0;l < n;l++)
                {
                    if(k == l)
                    {
                        continue;
                    }
                    if(pai[k].first - pai[l].first == p && pai[k].second - pai[l].second == q)
                    {
                        temp++;
                    }
                }
            }
            if(n - temp < ans)
            {
                ans = n - temp;
            }
        }
    }
    cout << ans << "\n";
    
    return 0;
}