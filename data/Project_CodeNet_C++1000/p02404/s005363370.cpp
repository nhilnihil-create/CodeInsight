#include <iostream>
using namespace std;
int main(){
int H,W;

for (;;){
    cin >> H >> W;
    if (H == 0&&W == 0)break;
    for (int a = 1;a <= W;a++){
        if (W == 0||H == 0)break;
        cout << "#";
    } 
    cout << endl;

    for (int b = 1;b <= H - 2;b++){
        if (W == 0 || H == 0)break;
        cout << "#";
        for (int c = 1;c <= W - 2;c++){
        cout << ".";
        }
        cout << "#" << endl;
    }

    for (int c = 1;c <= W;c++){
        if (W <= 1|| H <= 1)break;
        cout << "#";
    }
    cout << endl;
    cout << endl;
    }
    return 0;

}