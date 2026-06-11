#include <iostream>
#include <string>
using namespace std;
int main(void){
    int h,w;
    string str("#");
    while(1){
        cin>>h>>w;
        if(h==0&&w==0){
            break;
        }
        for(int i=0;i<h;i++){
            for(int i=0;i<w;i++){
            cout<<str;
            }
            cout<<endl;
        }
        cout<<endl;
    }
}