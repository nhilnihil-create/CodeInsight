#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main(){
    int tate,yoko,i=0,j=0,k=0;
    while(cin>>tate>>yoko){
        if(tate==0||yoko==0) break;
        for(i=1;i<=tate;i++){
            for(j=1;j<yoko;j++){
                if(i%2==1){
                    if(j%2==1)cout<<"#";
                    else cout<<".";
                    }
                else{
                    if(j%2==1)cout<<".";
                    else cout<<"#";
                }
            }
            if (yoko%2==0){
                if(i%2==1) cout<<"."<<endl;
                else cout<<"#"<<endl;
                }
            else{
                if(i%2==1) cout<<"#"<<endl;
                else cout<<"."<<endl;
            }
        }
    cout<<endl;
    }
    return 0;
}