#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, tmp, res = 0;
    cin >> n;
    
    for(int i = 0; i < n; ++i)
    {
        cin >> tmp;
        if(tmp % 2 && (i + 1) % 2)
        {
            res++;
        }
    }

    cout << res << "\n";
    return 0;
}