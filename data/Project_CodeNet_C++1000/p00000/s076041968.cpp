#include <iostream>
using namespace std;

int main() {
    for (int l = 1; l < 10; l++) {
        for (int r = 1; r < 10; r++) {
            cout << l << 'x' << r << '=' << l * r << endl;
        }
    }
    return 0;
}