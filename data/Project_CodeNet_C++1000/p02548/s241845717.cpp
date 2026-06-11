#include <bits/stdc++.h>

using namespace std;

long long n, ans = 0;
int main()
{
    cin >> n;
    int help = n % 3;
    for(long long i = 1; i < n; i++)
        ans += (n - 1) / i;
    cout << ans;     
    return 0;
}