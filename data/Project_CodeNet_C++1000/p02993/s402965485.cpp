#include<bits/stdc++.h>
using namespace std;

int main(){
    char ar[4];
    for(int i=0;i<4;i++){
        cin>>ar[i];
    }

    int x=0;
    for(int i=0;i<3;i++){
       if(ar[i]==ar[i+1]) {
        x++;
       }
    }
    if(x>0){
        cout<<"Bad"<<endl;
    }
    else{
        cout<<"Good"<<endl;
    }

}

