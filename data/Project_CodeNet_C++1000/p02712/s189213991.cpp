#include <iostream>
using namespace std;

int main(void)
{
    int n; cin >> n;
    long long ans = 0;
    for (int i = 1; i < n + 1; i++)
    {
        if (i % 3 > 0 && i % 5 > 0) ans += i;
    }
    cout << ans << endl;
}