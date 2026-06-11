#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int x,i,y,j;
    int chk=0;
    cin>>x;
    int* ar=(int*)malloc(x*sizeof(int));
    for(i=1;i<=x;i++){
        cin>>y;
        ar[i-1]=y;
    }
    for(j=0;j<x;j++){
        chk=chk^ar[j];
        }
       
    if(chk==0){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    
}
