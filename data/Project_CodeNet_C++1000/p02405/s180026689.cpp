#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    while (true) {
        int H, W;
        cin >> H >> W;
        if (H == 0 && W == 0)return 0;
        bool odd = true;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (odd) {
                    cout << '#';
                    odd = false;
                }
                else {
                    cout << '.';
                    odd = true;
                }
            }
            cout << endl;
            if (W % 2 == 0) {
                if (odd)odd = false;
                else odd = true;
            }
        }
        cout << endl;
    }
}
