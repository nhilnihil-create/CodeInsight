//
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t;
    t = 1;
    while (t--)
    {
        long long int k, j = 0, i;
        cin >> k;
        for (i = 1; i <= 1000000; i++)
        {
            j = (j * 10 + 7) % k;
            if (j == 0)
            {
                cout << i << " " << endl;
                return 0;
            }
        }
        cout << "-1" << endl;
    }
    return 0;
}