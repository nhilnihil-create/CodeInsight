#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    if(N>=11){
       N = N-(N/10)*10;
        
    }if(N==2||N==4||N==5||N==7||N==9){
        cout<<"hon"<<endl;
    }else if(N==0||N==1||N==6||N==8){
        cout<<"pon"<<endl;
    }else{
        cout<<"bon"<<endl;
    
    }
}