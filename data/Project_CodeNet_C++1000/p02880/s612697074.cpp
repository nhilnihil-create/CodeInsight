#include <iostream>
using namespace std;

int n, i, j, jwb;

int main (){
    jwb=0;
    cin>>j;
    for (int n=1; n<=9; n++){
        for (int i=1; i<=9; i++){
            if (n*i==j){
               jwb++;
            }
        }
    }if (jwb>0){
        cout<<"Yes"<<endl;
    }else {
        cout<<"No"<<endl;
    }
}