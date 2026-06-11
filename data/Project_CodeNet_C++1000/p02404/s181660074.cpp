#include <iostream>
using namespace std;

int main(void){

    int H;
    int W;

    while(1) {
        std::cin >> H >> W;
        if(H == 0 && W == 0) {
            break;
        }
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                if(i == 0 || i + 1 == H || j == 0 || j + 1 == W) {
                    cout << "#";
                } else {
                    cout << ".";
                }
                
            }
            cout << endl;
        }
        cout << endl;
    }
        
    return 0;
    
}