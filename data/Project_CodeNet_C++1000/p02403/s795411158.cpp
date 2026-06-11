#include <iostream>
using namespace std;
int main(void){
    int H,W;
    for(;;){
        cin>>H>>W;
        if(H==0,W==0){
            break;
        }
        for(int i=1;i<=H;i++){
            for(int y=1;y<=W;y++){
             cout<<"#";   
            }
            cout<<endl;
        }
        cout<<endl;
    }
}
