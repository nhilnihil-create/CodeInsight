#include <iostream>
#include <algorithm>
using namespace std;

using ull = unsigned long long;

int main() {

    ull l, r;

    cin >> l >> r;

    if(l + 2019 < r) { 
        r = l + 2019;
    }

    ull ans = 2019;

    for(ull i = l; i < r; ++i) {
        for(ull j = l + 1; j <= r; ++j) {

            ans = min(ans, (i * j) % 2019);

        }
    }

    cout << ans << endl;

    return 0;

}
