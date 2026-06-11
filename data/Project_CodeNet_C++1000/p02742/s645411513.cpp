#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>
#include <string>
#include <cmath>

# define PI 3.14159265358979323846

using namespace std;

int main(void) {
    long long h, w;
    cin >> h >> w;

    if (h == 1 || w == 1) {
        cout << 1 << endl;
        return 0;
    }

    long long ans = h * w;
    if (ans % 2 == 1) {
        ans = ans / 2 + 1;
    } else {
        ans = ans / 2;
    }
    cout << ans << endl;
}