#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    double a, b; cin >> a >> b;
    int ans = 1;
    double p1, p2;
    bool flag = false;
    while (ans <= 2000)
    {
        p1 = (double) ans * 0.08;
        p2 = (double) ans * 0.10;
        if (a <= p1 && p1 < a + 1 && b <= p2 && p2 < b + 1)
        {
            flag = true;
            break;
        }
        ans++;
    }
    if (flag) cout << ans << endl;
    else  cout << -1 << endl;
}