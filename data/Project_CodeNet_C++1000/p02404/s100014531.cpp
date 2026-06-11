#include <iostream>
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    while((H!=0)||(W!=0)){
        for(int i=0; i<W; i++) cout << "#";
        cout << endl;
        for(int i=0; i<H-2; i++){
            cout << "#";
            for(int j=0; j<W-2; j++){
                cout << ".";
            }
            cout << "#" << endl;
        }
        for(int i=0; i<W; i++) cout << "#";
        cout << endl;
        cout << endl;
        cin >> H >> W;
    }
    return 0;
}
