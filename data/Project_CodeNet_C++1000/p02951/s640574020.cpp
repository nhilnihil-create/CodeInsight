#include <cctype>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (c < a - b) {
        cout << 0;
    }
    else {
    cout << c - a + b;
    }
}
