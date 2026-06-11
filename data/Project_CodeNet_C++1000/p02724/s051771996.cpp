#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin >> x;
    int ans = x / 500;
    x %= 500;
    ans *= 1000;
    x /= 5;
    ans += x * 5;
    cout << ans << endl;
    return 0;
}