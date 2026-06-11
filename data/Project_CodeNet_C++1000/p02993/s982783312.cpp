#include<iostream>
using namespace std;
int main(){
    int isfalse=0;
    char adad[4];
    cin>>adad;
    for(int i=0;i<3;i++){
        if(adad[i]==adad[i+1]){
            isfalse=1;
            break;
        }
    }
    if(isfalse==1){
        cout<<"Bad";
    }
    else{
        cout<<"Good";
    }
}
