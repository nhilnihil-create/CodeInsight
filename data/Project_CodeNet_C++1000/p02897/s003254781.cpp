#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cout << fixed << setprecision(10);
    if(n == 1)cout << 1.00000000000 << endl;
    else if(n % 2 == 0)cout << 0.500000000 << endl;
    else {
        double x = n;
        cout << (n/2+1)/x << endl;
    }
}