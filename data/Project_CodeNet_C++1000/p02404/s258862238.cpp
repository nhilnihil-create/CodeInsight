#include <iostream>
using namespace std;

int main() {
    for (;;) {
        int H, W;
        cin >> H >> W;
        int _H, _W;
        _H = H - 1;
        _W = W - 1;

        if (H == 0 && W == 0) {
            break;
        } else {
            for (int i = 0; i < W; ++i) {
                cout << "#";
            }
            cout << endl;

            for (int i = 1; i < _H; ++i) {
                cout << "#";
                for (int j = 1; j < _W; ++j) {
                    cout << ".";
                }
                cout << "#";
                cout << endl;
            }

            for (int i = 0; i < W; ++i) {
                cout << "#";
            }
            cout << endl;
            cout << endl;
        }
    }
}