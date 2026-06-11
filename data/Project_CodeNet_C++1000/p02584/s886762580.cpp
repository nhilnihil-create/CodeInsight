#include <iostream>
using namespace std;

long long x, k, d;

int main() {
    cin >> x >> k >> d;
    if(abs(x/d) <= k) {
        k -= (x/d);
        x -= d*(x/d);
        if(k) {
            if(x >= 0 && abs(x-d) < abs(x)) {
                x -= d;
                k--;
            }
            else if(x < 0 && abs(x+d) < abs(x)) {
                x += d;
                k--;
            }
        }

        if(k%2 == 0) cout << abs(x);
        else cout << min(abs(x+d), abs(x-d));
    } else {
        if(x > 0) cout << abs(x-k*d);
        else cout << abs(x+k*d);
    }
}
