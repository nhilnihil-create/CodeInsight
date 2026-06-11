#include <iostream>
#include <string>
using namespace std;

int main(void){
    int H, W;
        
    string hori;
    int i;
    while(!cin.eof()){
        cin >> H >> W;
        if(!H && !W) return 0;
        hori = string(W, '#');
        
        for(i = 0; i < H; i++){
            cout << hori << endl;
        }
        
        cout << endl;
    }
    return 0;
}