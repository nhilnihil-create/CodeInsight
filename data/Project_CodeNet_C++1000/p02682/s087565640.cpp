#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int a,b,c,k;
    cin >> a >> b >> c >> k;
    if (a+b < k) cout << a + a + b - k << "\n";
    else if (a < k) cout << a << "\n";
    else cout << k << "\n";
    return 0;
}