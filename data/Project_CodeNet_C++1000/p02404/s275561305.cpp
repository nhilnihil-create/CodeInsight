#include <iostream>
using namespace std;
int main(void){
    int h,w;
    while(true){
        cin >> h>>w;
        if(h==0&&w==0)break;
        if(h<1||w<1)continue;
        
        for(int c=0;c<h;c++){
            for(int r=0;r<w;r++){
                if(r==0 || r== w-1 || c==0 || c==h-1){
                    cout << "#";
                }else{
                    cout << ".";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}