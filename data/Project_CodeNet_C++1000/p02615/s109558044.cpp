#include <bits/stdc++.h>
using namespace std;
int a[(int)2e5 + 1];
int main()
{

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n, std::greater<int>());
        long long ans = -a[0];
    for (int i = 0; i < n / 2; i++)
    {
        
        ans += a[i] * 2;
    }
    if (n % 2 == 1)
    {
        ans += a[n / 2];
    }
    cout<<ans;
}