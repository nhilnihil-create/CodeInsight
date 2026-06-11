#include <iostream>
using namespace std;

int main(){
    int n;
    int m;
    int r;
    char s;
    cin>>n;
    int card[4][13]={};
    for(int i=0; i<n;i++){
        cin>>s>>m;
    if(s=='S')r=0;
    if(s=='H')r=1;
    if(s=='C')r=2;
    if(s=='D')r=3;
        card[r][m-1]=1;
    }
    for(int i=0; i<4;i++){
        for(int t=0; t<13; t++){
            if(card[i][t]==0){
                if(i==0)cout<<"S "<<t+1<<endl;
                if(i==1)cout<<"H "<<t+1<<endl;
                if(i==2)cout<<"C "<<t+1<<endl;
                if(i==3)cout<<"D "<<t+1<<endl;
            }
        }
    }
    
    return 0;
}