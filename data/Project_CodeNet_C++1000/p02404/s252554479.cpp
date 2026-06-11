#include <iostream>
using namespace std;

int main(void) {
    int H, W;
    
    while(true) {
        cin >> H >> W;
        if(H == 0 && W == 0)   break;
        
        for(int w = 0; w < W; ++w) {
            cout << "#";
        }
        cout << endl;
        for(int h = 0; h < H - 2; ++h) {
            cout << "#";
            for(int w = 0; w < W - 2; ++w) {
                cout << ".";
            }
            cout << "#" << endl;
        }
        for(int w = 0; w < W; ++w) {
            cout << "#";
        }
        cout << endl;
        cout << endl;
    }
    return 0;
}
