#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, h, res = 0;
    cin >> n >> k;

    for(int i = 0; i < n; ++i)
    {
        cin >> h;
        if(h >= k) res++;
    }

    cout << res << "\n";
    return 0;
}
