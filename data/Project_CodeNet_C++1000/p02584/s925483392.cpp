#include <bits/stdc++.h>
using namespace std;
int main () {
    long long int x, k, d;
    cin >> x >> k >> d;
    x=abs(x);
    if (x/d>k) {
        cout << x-k*d << endl;
        return 0;
    }
    k-=x/d;
    if (k%2==0) {
        cout << x%d << endl;
    }
    else {
        cout << abs(x%d-d) << endl;
    }
}