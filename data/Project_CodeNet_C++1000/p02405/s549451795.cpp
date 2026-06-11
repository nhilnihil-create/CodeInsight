#include <iostream>
#include <string>
using namespace std;
int main(void){
    int x,y;
    string str="#";
    string ing=".";
    while(1){
        cin>>x>>y;
        if(x==0&&y==0){
            break;
        }
        for(int j=0;j<x/2;j++){
            for(int i=0;i<y/2;i++){
                cout<<str<<ing;
            }
            if(y%2==1){
                cout<<str<<endl;
            }
            else{
                cout<<endl;
            }
             for(int i=0;i<y/2;i++){
                cout<<ing<<str;
            }
            if(y%2==1){
                cout<<ing<<endl;
            }
            else{
                cout<<endl;
            }
        }
        if(x%2==1){
            for(int i=0;i<y/2;i++){
                cout<<str<<ing;
            }
            if(y%2==1){
                cout<<str<<endl;
            }
            else{
                cout<<endl;
            }
        }
        cout<<endl;
    }
}