#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int mxN = 2e5;
int n, a[mxN], ans, amt[1000001];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);

    for (int i = 0; i < n; i++)
    {
        for (int j = a[i]; j <= a[n - 1]; j += a[i]) amt[j]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (amt[a[i]] == 1) ans++;
    }

    cout << ans << "\n";
}