#include<iostream>

using namespace std;

int main () {

        int H,W;
        cin >> H >> W;
        while (H || W) {
                for (int i = 0; i < H; i++) {
                        for (int j = 0; j < W; j++) {
                                if (!i || i == H - 1 || !j || j == W - 1) {
                                        cout << "#";
                                } else {
                                        cout << ".";
                                }
                        }
                        if (W > 0) {
                                cout << endl;
                        }
                }
                cout << endl;
                cin >> H >> W;
        }

        return 0;

}