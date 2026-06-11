#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    int n;
    cin >> n;

    int ans;
    if (n == 100000) {
        cout << 90909 << endl;
    }
    else if (n%10000 != n) {
        ans = n - 10000 + 1 + 900 + 9;
        cout << ans << endl;
    }
    else if (n%1000 != n) {
        cout << 909 << endl;
    }
    else if (n%100 != n) {
        cout << n - 100 + 1 + 9 << endl;
    }
    else if (n%10 != n) {
        cout << 9 << endl;
    }
    else cout << n << endl;
    
    return 0;
}