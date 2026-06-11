#include <iostream>
#include <math.h>
#include <stdio.h>
#include <algorithm>

using namespace std;


int main()
{
    long double n = 0, d = 0, a = 0, b = 0, counter = 0;
    cin >> n >> d;
    while (n--) {
        cin >> a >> b;
        if (round(sqrt(pow(a, 2) + pow(b, 2)) <= d)) {
            counter++;
        }
    }
    cout << counter;
    return 0;
}