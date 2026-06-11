#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    long n, k; cin >> n >> k;
    long a = k;
    int ans = 1;
    while (a <= n)
    {
        a *= k;
        ans++;
    }
    cout << ans << endl;
}