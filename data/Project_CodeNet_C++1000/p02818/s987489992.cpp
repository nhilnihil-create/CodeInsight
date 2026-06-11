#include <bits/stdc++.h>

using namespace std;

int main() {
    long long a, b, k; cin >> a >> b >> k;
    long long num = min(k, a);
    a -= num; k -= num;
    b -= min(k, b);
    cout << a << " " << b << "\n";
}