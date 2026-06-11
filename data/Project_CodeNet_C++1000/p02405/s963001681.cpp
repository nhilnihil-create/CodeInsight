#include <iostream>
using namespace std;

int main() {
    int h, w;

    cin >> h >> w;

    while (h != 0 || w != 0) {
        for (int i = 0; i < h; i++) {
            for (int s = 0; s < w; s++) {
                if (i % 2 == 0) {
                    if (s % 2 == 0) {
                        cout << "#";
                    } else {
                        cout << ".";
                    }
                } else {
                    if (s % 2 == 0) {
                        cout << ".";
                    } else {
                        cout << "#";
                    }
                }
            }
            cout << endl;
        }
        cout << endl;
        cin >> h >> w;
    }

    return 0;
}