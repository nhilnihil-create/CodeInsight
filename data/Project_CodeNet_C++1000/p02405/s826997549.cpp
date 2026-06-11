#include <iostream>
using namespace std;

int main(void){
    int H, W;
        
    string hori;
    int i, j;
    bool b;
    
    while(!cin.eof()){
        cin >> H >> W;
        if(!H && !W) return 0;
        
        for(i = 0; i < H; i++){
            b = !(i % 2);
            for(j = 0; j < W; j++){
                cout << ((b)? '#' : '.');
                b = !b;
            }
            cout << endl;
        }
        cout << endl;
        
    }
    return 0;
}