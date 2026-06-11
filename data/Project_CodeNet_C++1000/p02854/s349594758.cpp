#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long int a[n + 1];
    a[0] = 0;
    for(int i = 1;i < n + 1;i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    long long int ans = LLONG_MAX;
    for(int i = 1;i < n + 1;i++)
    {
        long long int temp = fabs(a[i] - (a[n] - a[i]));
        if(temp < ans)
        {
            ans = temp;
        }
    }
    cout << ans << "\n";

    return 0;
}