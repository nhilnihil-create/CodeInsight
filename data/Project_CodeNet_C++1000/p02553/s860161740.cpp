#include <bits/stdc++.h>

using namespace std;

int main() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    long long res = 1;
    res = max(max(a * c, b * c), max(b * d, a * d));
    cout << res << '\n';
    return 0; 
}