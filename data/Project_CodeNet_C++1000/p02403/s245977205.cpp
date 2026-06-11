#include<iostream>
using namespace std;

inline void draw(char c, int n){
    for(int i = 0; i < n; i++) cout << c;
    cout << endl;
}

int main()
{
    int H, W, i;
    while(1){
        cin >> H >> W;
        if(H + W < 1) break;
        for(i = 0; i < H; i++) draw('#', W);
        cout << endl;
    }
    return 0;
}