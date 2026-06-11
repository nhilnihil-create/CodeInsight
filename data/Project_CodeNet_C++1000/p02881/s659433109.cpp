/**
 *    author:  FromDihPout
 *    created: 2020-08-08
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long n;
    cin >> n;
    long long ans = 0;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            long long j = n / i;
            ans = i + j;
        }
    }
    cout << ans - 2 << '\n';
    return 0;
}