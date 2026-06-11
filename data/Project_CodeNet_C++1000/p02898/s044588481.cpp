#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n, k, ans = 0;
    cin >> n >> k;
    while (n--)
    {
        int a;
        cin >> a;
        ans += a >= k;
    }
    cout << ans << "\n";
}