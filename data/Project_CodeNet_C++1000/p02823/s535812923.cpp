#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, a, b;
    cin >> n >> a >> b;

    if ((b-a)%2 == 0) cout << (b-a)/2 << endl;
    else if ((b-1) <= (n-a)) {
        if (b-a < 3) cout << b-1 << endl;
        else cout << b-1-(b-a-1)/2 << endl;
    }
    else {
        if (b-a < 3) cout << n-a << endl;
        else cout << n-a-(b-a-1)/2 << endl;
    }
}