#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int l, r, d;
    cin >> l >> r >> d;
    int ans = 0;
    for (; l <= r; l++)
    {
        if (l % d == 0)
            ans++;
    }
    cout << ans << endl;
}
