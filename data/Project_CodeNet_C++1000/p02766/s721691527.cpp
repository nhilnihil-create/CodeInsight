#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int ans = 0;
    while (1) {
        ans++;
        if (n/k != 0) n /= k;
        else break;
    }

    cout << ans << endl;
    
}