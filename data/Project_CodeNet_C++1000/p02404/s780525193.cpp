#include<bits/stdc++.h>
using namespace std;
int main(){

    int h,w;
    while(1){
        cin >> h >> w;
        if(h == 0 && w == 0)break;
        for(int i = 0; i < w; i++){
            cout << '#';
        }
        cout << endl;
        for(int i = 2; i < h; i++){
            cout << '#';
            for(int j = 2; j < w; j++){
                cout << '.';
            }
            cout << '#' << endl;
        }
        for(int i = 0; i < w; i++){
            cout << '#';
        }
        cout << endl << endl;

    }

}
