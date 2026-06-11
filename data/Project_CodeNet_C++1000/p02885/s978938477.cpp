#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
int a, b;
int main() {
    DAU
    cin >> a >> b;
    cout << max(a - 2 * b, 0);
    PLEC
}
