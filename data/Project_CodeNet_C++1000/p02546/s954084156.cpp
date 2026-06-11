#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int32_t main() {
    string s;
    cin >> s;
    if (s.back() == 's') {
        s += 'e';
        s += 's';
    }
    else {
        s += 's';
    }
    cout << s;
    return 0;
}
