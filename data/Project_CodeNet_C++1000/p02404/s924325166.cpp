#include <iostream>
using namespace std;
int main(void){
    int H,W,i,j,k;
    while(1){
        cin >> H >> W;
        if(H==0&&W==0) break;{
            for(i=0;i<W;i++){
                cout << "#";
            }
            cout << endl;
            for(j=0;j<H-2;j++){
                cout << "#";
                for(k=0;k<W-2;k++){
                    cout << ".";
                }
                cout << "#";
                cout << endl;
            }
            for(k=0;k<W;k++){
                cout << "#";
            }cout << endl;}
    cout << endl;}
}

