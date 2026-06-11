#include <iostream>
using namespace std;
int main(void){
    int H,W;
    for(int i = 0;i<10000;i++){
        cin>>H>>W;
     if(H == 0 && W == 0)
     {break;}
     for(int h = 0;h<H/2;h++){
         for(int w = 0;w<W/2;w++){
            cout<<"#"<<"."; 
            }
            if(W%2==1){cout<<"#";}
            cout<<endl;
         for(int o = 0;o<W/2;o++){
            cout<<"."<<"#"; 
            }
            if(W%2==1){cout<<".";}
            cout<<endl;
        }
     if(H%2==1){for(int p = 0;p<W/2;p++){
            cout<<"#"<<"."; 
            }
            if(W%2==1){cout<<"#";}
            cout<<endl;}
            cout<<endl;
    }
}
