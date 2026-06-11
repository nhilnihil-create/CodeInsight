#include <iostream>
using namespace std;
int main(){
int H,W;
int x,a,b;
for (;;){
    cin >> H >> W;
    if (H == 0 && W == 0) break;

    for (b = 1; b <= H; b++){

        for (a = 1; a <= W; a++){

            x = a + b;
            
            if (x % 2 == 0){
                cout << "#"; 

            }
          
            if (x % 2 != 0){
                cout << ".";

            }
        }
        cout << endl;
    } 
    cout << endl;
}

    return 0;


}