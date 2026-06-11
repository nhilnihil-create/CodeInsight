#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b, n;
    cin >> a >> b >> n;

    if (b-1 <= n) cout << a*(b-1)/b << endl;
    else cout << a*n/b << endl;
}