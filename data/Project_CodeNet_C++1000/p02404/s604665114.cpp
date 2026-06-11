#include <iostream>
#include <string>
using namespace std;
int main(void){
    int h,w;
    string str("#");
    string ing(".");
    while(1){
        cin>>h>>w;
        if(h==0&&w==0){
            break;
        }
        for(int i=0;i<w;i++){
            cout<<str;
        }
        cout<<endl;
            for(int i=0;i<h-2;i++){
                cout<<str;
                for(int i=0;i<w-2;i++){
                cout<<ing;
                }
                cout<<str<<endl;
            }
        for(int i=0;i<w;i++){
            cout<<str;
        }
        cout<<endl<<endl;
    }
}