#include <iostream>
using namespace std;

int main(){
    int h, w;
    while(cin >> h >> w && (h && w)){
        for(int i = 0; i < h; i++){
            if(i == 0 || i == h - 1) cout << string(w, '#') << endl;
            else cout << '#' << string(w - 2, '.') << '#' << endl;
        }
        cout << endl;
    }
}