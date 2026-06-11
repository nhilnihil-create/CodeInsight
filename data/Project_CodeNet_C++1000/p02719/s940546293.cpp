#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n, k;
    cin >> n >> k;
    if (abs(n - k) >= n)
        cout << n << '\n';
    else
        cout << min(abs(n % k), abs(n % k - k)) << '\n';
  
    return 0;
}