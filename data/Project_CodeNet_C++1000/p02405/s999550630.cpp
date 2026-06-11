#include <iostream>
using namespace std;

int main() {
    while (true) {
        int H, W;
        cin >> H >> W;
        if (H == 0 && W == 0) {
            break;
        }

        for (int hc = 0; hc < H; hc++) {
            for (int wc = 0; wc < W; wc++) {
                if ((hc + wc) % 2 == 0) {
                    cout << '#';
                } else {
                    cout << '.';
                }
            }
            cout << endl;
        }
        cout << endl;
    }
}