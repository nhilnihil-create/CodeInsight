#include <iostream>
using namespace std;

int main() {
    int H, W;

    while (cin >> H >> W, H) {
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cout << ((i+j)&1 ? ".": "#");
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}