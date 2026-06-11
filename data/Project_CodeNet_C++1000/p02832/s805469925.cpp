#include <bits/stdc++.h>
using namespace std;

const int NMAX = 2e5 + 5;
int n, val, x;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        if(x == val + 1) {
            val++;
        }
    }
    if(val == 0) {
        cout << -1;
    } else {
        cout << n - val;
    }
    return 0;
}