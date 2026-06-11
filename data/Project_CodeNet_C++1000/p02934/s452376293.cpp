#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;    
    double ans = 0.0;

    for (int i = 0; i < n; i++) {
    	int x; cin >> x;
    	ans += 1.0 / x;
    }

    cout << fixed << setprecision(12) << 1.0 / ans << "\n";

    return 0;
}