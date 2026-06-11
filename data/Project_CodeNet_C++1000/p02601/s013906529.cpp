#include <iostream>
#include <string>
using namespace std;

int main() {

    int red, green, blue;
    cin >> red >> green >> blue;

    int k;
    cin >> k;

    while (true) {
        if (red < green) {
            break;
        }
        green *= 2;
        k--;
    }

    while (true) {
        if (green < blue) {
            break;
        }
        blue *= 2;
        k--;
    }

    if (k >= 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
