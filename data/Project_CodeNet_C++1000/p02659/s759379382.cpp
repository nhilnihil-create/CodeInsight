#include <bits/stdc++.h>
using namespace std;


int main () {
    unsigned long long a;
    double b;
    cin >> a >> b;
    unsigned long long c = b * 100 + 0.5;
    unsigned long long d = a * c;
    cout << d / 100 << endl;
}