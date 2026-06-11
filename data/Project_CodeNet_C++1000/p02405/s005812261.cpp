#include<iostream>
using namespace std;

int main(){
    int h, w;
    
    while(1){
        cin >> h >> w;
        if(h == 0 && w == 0) break;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(i % 2 == 1 && j % 2 == 1) cout << '#';
                if(i % 2 == 1 && j % 2 == 0) cout << '.';
                if(i % 2 == 0 && j % 2 == 0) cout << '#';
                if(i % 2 == 0 && j % 2 == 1) cout << '.';
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
