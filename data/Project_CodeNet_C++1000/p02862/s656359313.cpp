#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

const long long mod = 1e9 + 7;

long long mod_pow(long long a, long long b, long long mod)
{
    if(b == 0) return 1;
    if(b & 1) return (a * mod_pow(a, b-1, mod)) % mod; 
    else 
    {
        long long x = mod_pow(a, b/2, mod);
        return (x * x) % mod;
    }
}

long long mod_comb(long long a, long long b, long long mod)
{
    b = min(a - b, b);
    long long faca = 1, facb = 1;
    for(int i=0; i<b; ++i)
    {
        faca = (faca * (a - i)) % mod;
        facb = (facb * (b - i)) % mod; 
    }

    return (faca * mod_pow(facb, mod-2, mod)) % mod;
}

int main()
{
    long long X, Y; cin >> X >> Y;

    int step = 0;
    while(true)
    {
        ++step;
        if(step > Y || step > X)
        {
            cout << 0 << endl;
            return 0;
        }
        if(Y - step + X - step == step)
            break;
    }

    long long X2 = X - step, X1 = step - X2;

    cout << mod_comb(X1 + X2, X1, mod) << endl;
}