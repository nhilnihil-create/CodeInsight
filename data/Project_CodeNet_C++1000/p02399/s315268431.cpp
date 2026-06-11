#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int d = a / b;
    int r = a%b;
    double f = (double)a / (double)b;
    cout << d << ' ' << r<<' ';
    printf("%.9f\n", f);
}
