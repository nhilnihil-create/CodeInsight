#include<bits/stdc++.h>
using namespace std;
long long int k, i, j, l, ans;
int main()
{
    cin >> k;
    for(i=1;i<=k;i++)
    {
        for(j=1;j<=k;j++)
        {
            for(l=1;l<=k;l++)
            {
                ans += __gcd(i, __gcd(j,l));
            }
        }
    }
    cout << ans << endl;
    return 0;
}
