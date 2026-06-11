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

    int a, b;
    cin >> a >> b;
    int out = -1;

    for (int i = 10 * b; i < 10 * b + 10; i++) {
        if (i*0.08 >= a && i*0.08 < a + 1) {
            out = i;
            break;
        }
    }

    cout << out;

    
    return 0;
}

