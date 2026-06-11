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
    long long k;
    cin >> k;

    int out = 0;
    
    for (int a = 1; a <= k; a++) {
        for (int b = 1; b <= k; b++) {
            for (int c = 1; c <= k; c++) {
                out += gcd(a, gcd(b, c));
            }
        }
    }

    cout << out;

    return 0;
}

