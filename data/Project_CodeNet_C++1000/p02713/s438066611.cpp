#include <iostream>

using namespace std;

int gcd(int x, int y) {
    if (y == 0)
        return x;
    else    
        return gcd(y, x%y);
}

int main() {
    int k;  cin >> k;
    long long ans = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            for (int l = 1; l <= k; l++) {
                int g = gcd(i, j);
                g = gcd(g, l);
                ans += g;
            }
        }
    }

    cout << ans << endl;

    return 0;
}