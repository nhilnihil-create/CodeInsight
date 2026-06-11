#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
int n, d;
int main() {
    DAU
    cin >> n >> d;
    d = 2 * d + 1;
    cout << n / d + (n % d != 0);
    PLEC
}
