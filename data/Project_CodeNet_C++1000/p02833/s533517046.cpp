#include <bits/stdc++.h>
using namespace std;

long long n, sol, p;

int main() {
    cin >> n;
    if(n % 2) {
        cout << 0;
    } else {
        p = 10;
        while(p <= n) {
            sol += n / p;
            p *= 5;
        }
        cout << sol;
    }
    return 0;
}