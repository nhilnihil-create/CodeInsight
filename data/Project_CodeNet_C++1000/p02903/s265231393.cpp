#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, a, b; cin >> n >> m >> a >> b;
    string l = string(a, '0') + string(m - a, '1');
    string o = string(a, '1') + string(m - a, '0');
    for(int i = 0; i < b; i++) cout << l << "\n";
    for(int i = b; i < n; i++) cout << o << "\n";
}