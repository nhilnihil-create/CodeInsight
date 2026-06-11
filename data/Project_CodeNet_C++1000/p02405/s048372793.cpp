#include <iostream>
using namespace std;
#include <cstdio>

int main() {
    int H, W;
    while(1){
        cin >> H >> W;
        if (H == 0 && W == 0) break;
        for (int i = 1; i <= H; i++){
            for (int j = 1; j <= W; j++){
                if (i % 2){
                    if (j % 2 == 0) cout << ".";
                    else cout << "#";
                }
                else {
                    if (j % 2 == 0) cout << "#";
                    else cout << ".";
                }
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}