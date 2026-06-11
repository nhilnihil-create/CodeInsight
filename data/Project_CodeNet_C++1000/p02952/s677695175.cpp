#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0,ans = 0,j = 0;
    cin >> n;

    for(int i = 1; i <= n; ++i)
    {
        int digit = 0;
        j = i;
        while (j != 0)
        {
            j /= 10;
            digit++;
        }
        if (digit % 2 == 1)
        {
            ans++;
        } 
    }
    cout << ans << endl;
}   