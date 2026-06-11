#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, a, b; cin >> n >> m >> a >> b;

    string line = string(a, '0') + string(m - a, '1');
    string other = string(a, '1') + string(m - a, '0');

    for(int i = 0; i < b; i += 1)
        cout << line << "\n";
    for(int i = b; i < n; i += 1)
        cout << other << "\n";
}
