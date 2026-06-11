#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, x, t;
    cin >> n >> x >> t;
    int a = n % x;
    int b = n / x;
    if(a == 0) cout << b * t << endl;
    else cout << b * t + t << endl;
}