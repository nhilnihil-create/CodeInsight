#include <iostream>
#include <string>
using namespace std;
int main(void){
    
    int X, Y;
    cin >> X >> Y;
    
    for(int turu = 0; turu <= X; turu++){
        int kame = X - turu;
        int asi = (2 * turu) + (4 * kame);
        if(asi == Y){
            cout << "Yes" << endl;
            return 0;
        }
    }
    
    cout << "No" << endl;
}
