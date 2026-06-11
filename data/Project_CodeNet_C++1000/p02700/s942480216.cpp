#include <iostream>

using namespace std;

int main() {

    int x, y, a, b;
    cin >> x >> y >> a >> b;
    while(1) {
        a -= y;
        if (a <= 0) {
            cout << "Yes";
            break;
        }
        x -= b;
        if (x <= 0) {
            cout << "No";
            break;
        }
    }
    return 0;
}