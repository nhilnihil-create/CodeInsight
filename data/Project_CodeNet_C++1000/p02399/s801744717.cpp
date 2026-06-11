#include <bits/stdc++.h>

using namespace std;

int main()
{
    long a, b;
    cin >> a >> b;

    long d = a / b;
    long r = a % b;
    double f = (double)a / (double)b;
    printf("%ld %ld %.5f\n", d, r, f);
}

