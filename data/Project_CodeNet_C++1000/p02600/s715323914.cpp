#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, res;
    cin >> x;

    int j = 8;
    for(int i = 600; i <= 2000; i += 200, --j)
    {
        if(x < i)
        {
            res = j;
            break;
        }
    }

    cout << res << "\n";
    return 0;
}