#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int64_t V = 0, E = 0;
    
    for (int64_t i = 1; i <= n; i++) V += i * (n - i + 1);
    
    for (int i = 0; i < n - 1; i++) {
        int64_t a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        E += a * (n - b + 1);
    }
    cout << V - E << "\n";
    return 0;
}
