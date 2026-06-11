#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a, v, b, w, t, i, j, c = 0;
    cin >> a >> v >> b >> w >> t;
    if (a == b)
    {
        cout << "YES" << endl;
        return 0;
    }
    if (a <=b) {
        for (i = 1; i <= t; i++)
        {
            a += v;
            b += w;
            if (a >= b)
            {
                cout << "YES" << endl;
                return 0;
            }

        }
        cout << "NO" << endl;
        return 0;
    }else
    {
         for (i = 1; i <= t; i++)
        {
            a -= v;
            b -= w;
            if (a <= b)
            {
                cout << "YES" << endl;
                return 0;
            }

        }
        cout << "NO" << endl;
        return 0; 
    }
}
