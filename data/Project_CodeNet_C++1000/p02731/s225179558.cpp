#include <bits/stdc++.h>
using namespace std;
typedef long double ll;

ll L;

int main() { 
    cin >> L;
    ll a, b, c, out;
    a = L / 3;
    b = L / 3;
    c = L / 3;
    out = a * b * c;
    cout << fixed << setprecision(6) << out << endl;
    return 0;
}