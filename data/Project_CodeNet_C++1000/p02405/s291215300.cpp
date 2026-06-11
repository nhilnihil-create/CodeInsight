#include <iostream>
using namespace std;

int main(void) {
    int H, W;
    int checkH = 1;
    int checkW = 1;
    
    while(true) {
        cin >> H >> W;
        
        if(H == 0 && W == 0)   break;
        
        checkH = 1;
        checkW = 1;
        for(int h = 0; h < H; ++h) {
            checkW = checkH;
            for(int w = 0; w < W; ++w) {
                if(checkW == 1) {
                    cout << "#";
                    checkW = 0;
                } else {
                    cout << ".";
                    checkW = 1;
                }
            }
            cout << endl;
            
            if(checkH == 1) {
                checkH = 0;
            } else {
                checkH = 1;
            }
        }
        cout << endl;
    }
    return 0;
}
