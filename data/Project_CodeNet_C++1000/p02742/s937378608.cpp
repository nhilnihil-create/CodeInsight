#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace boost::multiprecision;

int main() {
    cpp_int h, w;
    cin >> h >> w;

    cpp_int tmp = h * w;
    if (h == 1 || w == 1) {
        cout << 1 << endl;
    }
    else if (h % 2 == 0 || w % 2 == 0) {
        cout << tmp/2 << endl;
    }
    else {
        cout << tmp/2 + 1 << endl;
    }
}
