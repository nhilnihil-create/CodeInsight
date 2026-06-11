#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x, y;
    long long a, b;
    double k;
    cin >> a >> b;
    if(a != b)
    {
        k = (a+b)*0.5;
        if(k == int (k))
        {
            x = abs (a-k);
            y = abs (b-k);
            if (x == y)
            {
                cout << fixed << setprecision(0) << k << endl;
            }
            else
            {
                cout << "IMPOSSIBLE" << endl;
            }
        }
        else
        {
            cout << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}
