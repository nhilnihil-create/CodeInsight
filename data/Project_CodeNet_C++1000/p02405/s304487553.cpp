#include<iostream>
using namespace std;

inline void draw(int i, int j){
    if((i + j) % 2 == 0){ cout << '#'; }else{ cout << '.'; }
}

int main()
{
    int H, W, i, j;
    while(1){
        cin >> H >> W;
        if(H + W < 1) break;
        for(i = 0; i < H; i++){
            for(j = 0; j < W; j++) draw(i, j);
            cout << endl;
        }
        cout << endl;
    };
    return 0;
}
     