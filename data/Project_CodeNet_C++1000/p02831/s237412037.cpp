#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
long long a, b, c;
int main() {
    DAU
    cin >> a >> b;
    c = a * b / __gcd(a, b);
    cout << c;
    PLEC
}
