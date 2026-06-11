#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int a,b,c,count;
    count=0;
    cin>>a>>b>>c;
    for(int i=a;i<b+1;i++){
        if(i != 0 && c%i==0){
            count++;
        }
    }
    cout<<count<<endl;
    }