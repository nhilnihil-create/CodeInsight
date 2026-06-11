#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int main()
{

    int x, y;
    cin >> x>>y;
    long long s = 0;
    if (x <= 3) {
        if (x == 1) {
            s += 300000;
        }
        else if (x == 2) {
            s += 200000;
        }
        else s += 100000;
    }
    if (y <= 3) {
        if (y == 1) {
            s += 300000;
        }
        else if (y == 2) {
            s += 200000;
        }
        else s += 100000;
    }
    if (y == 1 && x == 1) {
        s += 400000;
    }
    cout << s;
    return 0;
}