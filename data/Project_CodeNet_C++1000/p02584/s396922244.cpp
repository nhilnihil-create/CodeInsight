#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ll x, k, d; cin >> x >> k >> d;

    if (x < 0)
        x = -x;

    if (x / d >= k)
        cout << x - d * k << endl;
    else {
        if ((k-x/d) % 2 == 0)
            cout << x%d << endl;
        else 
            cout << d - x%d << endl;
    }
    return 0;
}