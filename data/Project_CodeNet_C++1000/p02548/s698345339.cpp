//in the name of god
#include <bits/stdc++.h>

using namespace std;

int n, ans;

int main()
{   
    cin >> n;
    for(int i = 1; i < n; i ++)
    {
        ans += (n - 1) / i;
    }

    cout << ans << '\n';
    return 0;
}