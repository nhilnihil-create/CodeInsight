#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, w;
    char d = '.';
    while(true){
        cin >> h >> w;
        if(h == 0 && w == 0)
            break;
        for(int i = 0; i < h; i++){
            if(i == 0 || i == (h - 1)) {
                for (int j = 0; j < w; j++) {
                    cout << '#';
                }
            }
            if(i > 0 && i < (h - 1)){
                cout << '#';
                for(int i = 0; i < (w - 2); i++){
                    cout << '.';
                }
                cout << '#';
            }
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;
}