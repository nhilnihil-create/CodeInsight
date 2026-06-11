#include <bits/stdc++.h>
using namespace std;

int a, b;

void solve() {
    cin >> a >> b;
    cout << (a > 9 || b > 9 ? -1 : a * b) << "\n";
}

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    
}