#include <iostream>
using namespace std;
int main(){
    char mark[] = "#.";
    int t, H, W;
    while(1){
        cin >> H >> W;
        if(H == 0 && W == 0){
            break;
        }
        for(int i = 0; i < H; i++){
            t = i % 2;
            for(int j = 0; j < W; j++){
                cout << mark[t];
                 t = (t+1) % 2;
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}