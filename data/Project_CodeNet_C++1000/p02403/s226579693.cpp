#include <iostream>
using namespace std;
int main(void){
    int H,W; char a; a='#';
    for(int i=0; i<300; i++){
        cin>>H>>W;
        if(H==0&&W==0){
            break;
        }
        for(int h=0; h<H;h++){
            for(int j=0; j<W;j++){
            cout<<a;
            }
            cout<<endl;
    }
    cout<<endl;
    }
}



