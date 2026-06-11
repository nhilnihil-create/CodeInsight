#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
const long long int k = 998244353;
int main()
{
    int n;
    cin >> n;
    int d[n];
    long long int a[100010] = {};
    int Max = 0;
    for(int i = 0;i < n;i++)
    {
        cin >> d[i];
        if(d[i] > Max)
        {
            Max = d[i];
        }
        a[d[i]]++;
    }
    if(d[0] != 0 || a[d[0]] != 1)
    {
        cout << "0\n";
        return 0;
    }
    long long int ans = 1;
    for(int i = 1;i <= Max;i++)
    {
        long long int x = 1,y = a[i - 1];
        for(int j = 0;j < a[i];j++)
        {
            x *= y;
            x = x % k;
        }
        ans *= x;
        ans = ans % k;
    }
    cout << ans % k << "\n";
    
    return 0;
}