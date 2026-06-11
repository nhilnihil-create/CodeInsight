#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(void) {
    int x, y;
    cin >> x >> y;

    if (y % 2) {
        cout << "No" << endl;
        return 0;
    }

    if (y/2-x < 0 || x*2-y/2 < 0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}