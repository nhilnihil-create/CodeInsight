#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, ans = 0;
    cin >> n;

    for (size_t i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if(i % 2 == 1)
        {
            if(x % 2 == 1)
            {
                ans++;
            }
        }
    }

    cout << ans;
    

    return 0;
}