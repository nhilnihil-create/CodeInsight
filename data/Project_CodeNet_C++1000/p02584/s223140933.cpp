#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x, k, d;
    cin >> x >> k >> d;

    x = abs(x);
    if (x/d >= k) cout << x-k*d << endl;
    else { 
        if ((k-x/d)%2 == 0) cout << x%d << endl;
        else cout << d-x%d << endl;
    }
}
