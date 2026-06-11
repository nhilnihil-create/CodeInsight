#include <iostream>
using namespace std;
int main(void){
    int h,w;
    while(true){
        cin >> h>>w;
        if(h==0&&w==0)break;
        if(h<1||w<1)continue;
        
        for(int r=0;r<h;r++){
            for(int c=0;c<w;c++){
                cout << "#";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}