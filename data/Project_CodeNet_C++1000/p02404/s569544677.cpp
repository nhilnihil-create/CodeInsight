#include <iostream>
using namespace std;

int main() {
    int h, y;

    cin >> h >> y;

    while (h != 0 || y != 0) {
        if (h == 1 || h == 2) {
            for (int i = 0; i < h; i++) {
                for (int s = 0; s < y; s++) {
                    cout << "#";
                }
                cout << endl;
            }
        } else {
            for (int i = 0; i < h; i++) {
                if (i == 0 || (i + 1) == h) {
                    for (int s = 0; s < y; s++) {
                        cout << "#";
                    }
                    cout << endl;
                } else {
                    for (int s = 0; s < y; s++) {
                        if (s == 0 || (s + 1) == y) {
                            cout << "#";
                        } else {
                             cout << ".";
                        }
                    }
                    cout << endl;
                }
            }
        }
        cout << endl;
        cin >> h >> y;
    }

    return 0;
}