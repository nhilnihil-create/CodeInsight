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
        cout << hori << endl;
        
        hori = "#" + string(W - 2, '.') + "#";
        
        for(i = 1; i < H - 1; i++){
            cout << hori << endl;
        }
        
        hori = string(W, '#');
        cout << hori << endl;
        
        cout << endl;
    }
    return 0;
}