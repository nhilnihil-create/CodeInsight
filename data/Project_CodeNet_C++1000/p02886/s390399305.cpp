#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n, a[50];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ans += a[i] * a[j];
        }
    }
    cout << ans << "\n";
}