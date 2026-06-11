#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long a;
    double b;
    cin >> a >> b;
    double c = b * 100;
    long long d = lround(c);
    long long product = d * a;
    cout << product / 100;
}
