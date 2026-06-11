#include <iostream>
using namespace std;

int main() {
    while(1){
        int H, W;
        char c[2] = {'#', '.'};
        cin >> H >> W;
        if (H == 0 && W == 0){
            break;
        }
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                cout << c[(i+j) % 2];
            }
            cout << endl;
        }
        cout << endl;
    }
}