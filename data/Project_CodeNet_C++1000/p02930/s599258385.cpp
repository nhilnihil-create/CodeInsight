#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, l, a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int y = i+1; y < n; y++)
        {
            for (int u = 0; u < 20; u++)
            {
                l = (1 << u);
                if ((i & l) != (y & l))
                {
                    cout << u+1 << " ";
                    break;
                }
            }
        }
        cout << "\n";
    }
    return 0;
}
