#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;


int main()
{
    long long n, k;
    cin >> n >> k;
    long long x = n % k;
    while (true) {
        long long y = abs(x-k);
        if (y >= x) break;
        x = y;
    }
    cout << x << '\n';
   
    return 0;
}