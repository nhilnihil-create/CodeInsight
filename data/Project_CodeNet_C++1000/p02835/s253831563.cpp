#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b + c <= 21) {
        cout << "win" << endl;
    }
    else {
        cout << "bust" << endl;
    }
}