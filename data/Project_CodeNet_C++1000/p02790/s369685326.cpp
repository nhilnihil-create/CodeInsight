#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e5 +7;

#include <math.h>
#define PI 3.14159265358979323846264338327950L



int main() {
    int a, b;
    cin >> a >> b;

    if (a > b) {
        for (int i = 0; i < a; i++) cout << b;
    }
    else {
        for (int i = 0; i < b; i++) cout << a;
    }
    return 0;
}