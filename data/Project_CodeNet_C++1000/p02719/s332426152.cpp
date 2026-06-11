#include<iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

int gcd(int p, int q) {
    if (p % q == 0)return q;
    return gcd(q, p % q);
}

int main()
{
    long long n,k;
    cin >> n>>k;

    long long min = n;
    long long ab1=n,ab2=n;

    long long amari;
    amari = n % k;

    if (amari * 2 <= k) {
        cout << amari;
    }
    else {
        cout << llabs(amari - k);
    }

    
    return 0;
}

