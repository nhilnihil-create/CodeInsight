#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
long long k,ans;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> k;
    for(int i = 1; i <= k; i++)
    {
        for(int g = 1; g <= k; g++)
        {
            for(int j = 1; j <= k; j++)
                ans += __gcd(__gcd(i,g),j);
        }
    }
    cout << ans;
}
