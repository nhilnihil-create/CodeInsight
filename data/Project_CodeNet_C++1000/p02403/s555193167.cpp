#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(void) {
    int H, W;
    
    cin >> H >> W;
    
    while( !(H == 0 && W == 0) ) {
        for(int h=1; h<=H; h++) {
            for(int w=1; w<=W; w++) {
                cout << '#';
            }
            cout << endl;
        }
        cout << endl;
        
        cin >> H >> W;
    }
    
    return 0;
}