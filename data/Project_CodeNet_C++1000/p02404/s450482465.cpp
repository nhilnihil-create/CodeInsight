#include <iostream>
using namespace std;
int main(void){
    int H, W;
    while (true) {
        cin >> H >> W;
        if (H == 0 && W == 0) break;
        for (int y = 0; y < H; y++) {
            for (int x = 0; x < W; x++) {
                if (x == 0 || x == W - 1 || y == 0 || y == H - 1) {
                    cout << '#';
                } else {
                    cout << '.';
                }
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}