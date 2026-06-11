#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <string.h>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long h;
    long long mob = 1;
    long long attack = 0;
    cin >> h;
    while (h > 0) {
        attack += mob;
        h /= 2;
        mob *= 2;
    }
    cout << attack << '\n';
}