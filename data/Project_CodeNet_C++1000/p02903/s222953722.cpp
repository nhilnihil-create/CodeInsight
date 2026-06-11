#include<bits/stdc++.h>
using namespace std;

int main(){
    int h, w, a, b;
    cin >> h >> w >> a >> b;

    int ma[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            ma[i][j] = 0;
        }
    }

    for(int i = 0; i < b; i++){
        for(int j = 0; j < a; j++){
            ma[i][j] = 1;
        }
    }

    for(int i = b; i < h; i++){
        for(int j = a; j < w; j++){
            ma[i][j] = 1;
        }
    }

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cout << ma[i][j];
        }
        cout << endl;
    }
}