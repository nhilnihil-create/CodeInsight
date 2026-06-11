#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    Int a, b, c; cin >> a >> b >> c;
    Int d = c - a - b;
    if ((Int)4 * a * b < (Int)d*d && d>0)
        puts("Yes");
    else
        puts("No");
}