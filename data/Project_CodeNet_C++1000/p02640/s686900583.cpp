#include <bits/stdc++.h>

using namespace std;

int main()
{   int x, y;
    int b = 0;
    cin >> x >> y;
    for (int i = 0; i <= 100; ++i)
    {
            for (int j = 0; j <= 100; ++j)
            {
                if ((i + j == x) && (4*j+ 2*i == y))
                    b = 1;
            }
    }
        if (b == 1)
            cout << "Yes";
        else
            cout << "No";
   

}

