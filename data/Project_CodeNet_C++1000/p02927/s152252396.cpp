#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main()
{
    int m,d;
    cin >> m >> d;
    int d1 = d / 10,d2 = d % 10;
    int ans = 0;
    for(int i = 1;i <= m;i++)
    {
        for(int j = 2;j <= d1;j++)
        {
            for(int k = 2;k <= 9;k++)
            {
                if(10 * j + k > d)
                {
                    break;
                }
                if(i == j * k)
                {
                    ans++;
                }
            }
        }
    }
    cout << ans << "\n";
    
    return 0;
}