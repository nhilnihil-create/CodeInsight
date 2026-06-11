#include <iostream>
using namespace std;
int main(void){
    int H,W,i,j;
    while(1){
        cin >> H >> W;
        if(H==0&&W==0) break;
    
    for(i=1;i<=H;++i){
        if(i%2){
        for(j=1;j<=W;++j){
            if(j%2){
                cout << "#";
            }else{
                cout << ".";
            }
        }    
        }else{
            for(j=1;j<=W;++j){
                if(j%2){
                cout << ".";    
                }else{
                cout << "#";
                }
            }
        }cout << endl;
    }
    cout << endl;}
}
