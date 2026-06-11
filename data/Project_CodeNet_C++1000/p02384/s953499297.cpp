#include <iostream>
#include <stdio.h>
using namespace std;
int tmp,D[100]={},ans;
void north(){
    tmp=D[0];
    D[0]=D[1];
    D[1]=D[5];
    D[5]=D[4];
    D[4]=tmp;
}
void south(){
    tmp=D[0];
    D[0]=D[4];
    D[4]=D[5];
    D[5]=D[1];
    D[1]=tmp;
}
void east(){
    tmp=D[0];
    D[0]=D[3];
    D[3]=D[5];
    D[5]=D[2];
    D[2]=tmp;
}
void west(){
    tmp=D[0];
    D[0]=D[2];
    D[2]=D[5];
    D[5]=D[3];
    D[3]=tmp;
}
void around(){
    tmp=D[1];
    D[1]=D[3];
    D[3]=D[4];
    D[4]=D[2];
    D[2]=tmp;
}
void serch(int a){
    for(int k=0;k<6;k++){
        if(a==D[k]){
            ans=k;
            break;
        }
    }
    if(ans==1){
        north();
    }
    else if(ans==2){
        west();
    }
    else if(ans==3){
        east();
    }
    else if(ans==4){
        south();
    }
    else if(ans==5){
        south();
        south();
    }
}
int main(){
    int n,a,b;
    for(int i=0;i<6;i++){
        cin>>D[i];
    }
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        serch(a);
        while(1){
            if(b==D[1]){
                break;
            }
            around();
        }
        cout<<D[2]<<endl;
    }
    return 0;
}
