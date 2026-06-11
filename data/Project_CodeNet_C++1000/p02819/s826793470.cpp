#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isPrime(int n)
{
    if(n <= 1) return false;
    if(n <= 2) return true;
    if(n % 2 == 0) return false;

    for(int i = 3; i < sqrt(n); ++i)
    {
        if(n % i == 0) return false;
    }
    return true;
}

int main()
{
    int x;
    cin >> x;

    if(isPrime(x))
        cout << x << "\n";
    else 
    {
        bool found = false;
        while(!found)
        {
            x++;
            if(isPrime(x)) 
                found = true;
        }
        cout << x << "\n";
    }
    return 0;
}