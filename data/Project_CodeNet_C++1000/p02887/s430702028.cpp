#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, res = 0;
    string a;
    cin >> n >> a;

    if(n == 1)
    {
        cout << 1 << "\n";
        return 0;
    }
    for(int i = 0; i < n - 1; ++i)
    {
        if(i == n - 2)
        {
            if(a[i] == a[i + 1]) 
                res++;
            else 
                res += 2;
        } else if(a[i] != a[i + 1])
        {
            res++;
        }
    }
    cout << res << "\n";
    return 0;
}