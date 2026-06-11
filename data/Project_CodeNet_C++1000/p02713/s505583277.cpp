#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using p = pair<int, int>;


int gcd(int a, int b) 
{ 
    if (a == 0) return b; 
    return gcd(b % a, a); 
} 

int main()
{
    int n;
    ll res = 0;
    cin >> n;

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            int ij = gcd(i, j);
            for(int k = 1; k <= n; ++k) 
                res += gcd(ij, k);
        }
    }

    cout << res << "\n";
    return 0;
}