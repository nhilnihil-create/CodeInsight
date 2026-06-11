#include <iostream>
using namespace std;

int main() {
    int h, y;

    cin >> h >> y;

    while (h != 0 || y != 0) {
        for (int i = 0; i < h; i++) {
            for (int s = 0; s < y; s++) {
                cout << "#";
            }
            cout << endl;
        }
        cout << endl;
        cin >> h >> y;
    }

    return 0;
}