#include <bits/stdc++.h>
using namespace std;

long long a, b;
long long nr = 1;

int main() {
    cin >> a >> b;
    long long n = __gcd(a, b);
    for(long long i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            nr++;
            while(n % i == 0) {
                n /= i;
            }
        }
    }
    if(n > 1) {
        nr++;
    }
    cout << nr;
    return 0;
}