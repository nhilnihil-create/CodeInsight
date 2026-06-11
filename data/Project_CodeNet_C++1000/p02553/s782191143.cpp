#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b, c, d; cin >> a >> b >> c >> d;
    long long acd = max(a*c, a*d);
    long long bcd = max(b*c, b*d);
    cout << max(acd, bcd) << endl;
}