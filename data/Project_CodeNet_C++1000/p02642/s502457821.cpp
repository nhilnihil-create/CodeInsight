#include <algorithm>
#include <iostream>
using namespace std;
int n, a[200010];
int m[1000010];
int main()
{
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (!m[a[i]])
        {
            for (int j = a[i]; j <= 1000000; j += a[i])
            {
                m[j] = true;
            }
            if (i == n - 1 || a[i] != a[i + 1]) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
