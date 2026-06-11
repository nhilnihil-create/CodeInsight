//
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int tt;
    tt = 1;
    while (tt--)
    {
        double d, t, s;
        cin >> d >> t >> s;
        if ((d / s) <= t)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}