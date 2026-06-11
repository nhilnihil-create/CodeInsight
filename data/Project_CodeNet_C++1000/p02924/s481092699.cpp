#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
long long n, res;
int main() {
    DAU
    cin >> n;
    res = n * (n - 1) / 2;
    cout << res;
    PLEC
}
