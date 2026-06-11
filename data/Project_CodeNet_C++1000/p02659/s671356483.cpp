#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a;
    double b;
    cin >> a >> b;
    long long c = b * 100 + 0.001;
    long long ans = (a * c) / 100;
    cout << ans << endl;
    return 0;
}