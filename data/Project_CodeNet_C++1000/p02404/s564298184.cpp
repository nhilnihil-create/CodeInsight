#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int main(){

    int H, W = -1;

    queue<int> que_h;
    queue<int> que_w;

    while(1){
        if((H == 0) && (W == 0)){
            break;
        }
        cin >> H >> W;
        que_h.push(H);
        que_w.push(W);
    }

    while(1){
        
        H = que_h.front();
        W = que_w.front();

        if((H == 0) && (W == 0)){
            break;
        }

        for(int i=0; i<W; i++){
            cout << "#";
        }
        cout << endl;
        // contents
        for(int i=0; i<H-2; i++){
            for(int j=0; j<W; j++){
                if((j == 0) || (j == W-1)){
                    cout << "#";
                }else{
                    cout << ".";
                }
            }
            cout << endl;
        }
        
        for(int i=0; i<W; i++){
            cout << "#";
        }
        cout << endl;
        cout << endl;

        que_h.pop();
        que_w.pop();
    }


    return  0;
}