#include <bits/stdc++.h>

using namespace std;
const int max_r = 123456 * 2 + 1;
const int sqrt_max = int(sqrt(max_r));

bool np[max_r];

int main()
{
    np[0] = np[1] = true;
    for(int i=2; i<=sqrt_max; i++)
    {
        if(!np[i])
        {
            for(int j=2*i; j<max_r; j+=i)
            {
                np[j] = true;
            }
        }
    }
    
    int n;
    while(cin >> n, n)
    {
        int ct = 0;
        for(int i=n+1; i<=2*n; i++)
        {
            if(!np[i])
            {
                ct++;
            }
        }
        cout << ct << endl;
    }

}