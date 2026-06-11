#include<iostream>
using namespace std;
#define MAX 300

int main(void)
{
    int H,W;


    while(1){
        do{
            cin >> H >> W;
        }while(H < 0 || H > MAX || W < 0 || W > MAX);
         
        if(W == 0 && H == 0) break;

        for(int i = 0;i < H;i++){
             for(int j = 0;j < W;j++){
                 if((i + j) % 2 == 0) cout << "#";
                 else cout << ".";
             }
             cout << endl;
        }
        cout << endl;

    }
    return 0;
}