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
    double l;
    cin >> l;
    double o;

    if ((int)l % 3 == 0) {
        o = (l / 3)*(l / 3)*(l / 3);
        printf("%0.12f\n", o);
    }
    else {
        o = (l / 3)*(l / 3)*(l / 3);
        printf("%0.12f\n", o);
    }

    
    return 0;
}

