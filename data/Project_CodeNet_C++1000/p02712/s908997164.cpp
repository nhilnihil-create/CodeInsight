#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, f, b;
    ll res = 0;
    cin >> n;

    for(int i = 1; i <= n; ++i)
    {
        f = i % 3 == 0, b = i % 5 == 0;
        
        if(!f && !b) res += i; 
    }

    cout << res << "\n";
    return 0;
}