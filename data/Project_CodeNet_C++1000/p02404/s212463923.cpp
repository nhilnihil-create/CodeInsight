#include <iostream>
#include <string>

using namespace std;
int main(int argc, const char * argv[]) {
    int H,W;
    int i,j;
    while (true) {
        cin >> H >> W;
        if(H == 0 && W == 0) break;
        else{
            for (j=0; j<H; j++) {
                if (j==0||j==H-1) {
                    for (i=0; i<W; i++){
                        cout << '#';
                    }
                    cout << endl;
                }else {
                    for (i=0; i<W; i++){
                        if(i==0 ||i==W-1)
                            cout << '#';
                        else cout << '.';
                    }
                    cout << endl;
                }
            }
            cout << endl;
        }
    }
    return 0;
}