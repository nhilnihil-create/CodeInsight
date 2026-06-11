#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
string a, b;
int res;
int main() {
    DAU
    cin >> a >> b;
    for (int i = 0; i < 3; ++i)
        res += (a[i] == b[i]);
    cout << res;
    PLEC
}
