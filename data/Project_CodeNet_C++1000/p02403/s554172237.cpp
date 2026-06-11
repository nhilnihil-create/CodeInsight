#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int H, W, i1, i2;
    
    
    while (1) {
    
        cin >> H >> W;
        if (H == 0 && W == 0) break;
            
        for (i1=0; i1<H; i1++) {
            
            for (i2=0; i2<W; i2++){
                cout << "#";
            }
            
            cout << "\n";
        }
        
        cout << endl;
        
    }
    
}