#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;

int main() {
    int a, b;
    cin >> a >> b;
    if (a <= 9 && b <= 9) {
        cout << a * b << endl;
    }
    else {
        cout << -1 << endl;
    }
}
