#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        if (i % 2 == 1 && t % 2 == 1)
            ans++;
    }
    cout << ans << endl;
}
