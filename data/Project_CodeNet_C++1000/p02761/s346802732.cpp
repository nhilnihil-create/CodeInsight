#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n, m; cin >> n >> m;
    bool flag = true;
    int s, c;
    int a[5]; for (int i = 0; i < 5; i++) a[i] = -1;
    for (int i = 0; i < m; i++)
    {
        cin >> s >> c;
        if (n < s)
            flag = false;
        else if (a[s - 1] > -1 && a[s - 1] != c)
            flag = false;
        else
            a[s - 1] = c;
    }
    if (a[0] == 0 && n > 1)
        flag = false;
    int ans;
    if (flag)
    {
        ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > -1) ans = ans * 10 + a[i];
            else
            {
                if (i == 0 && n > 1) ans = 1;
                else if (i == 0 && n == 0) ans = 0;
                else ans *= 10;
            }
        }
    }
    else
    {
        ans = -1;
    }
    
    cout << ans << endl;
}