#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

#include <math.h>
#define PI 3.14159265358979323846264338327950L



int main() {
    int a, b;
    cin >> a >> b;
    if (a > 9 || b > 9) {
        cout << -1 << endl;
    }
    else {
        cout << a * b;
    }
    return 0;
}