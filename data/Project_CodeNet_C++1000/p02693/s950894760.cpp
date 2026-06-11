#include <iostream>
#include<stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int a,b,k;
    cin >>k>> a >> b ;
    int i,result=-1;
    for(i=a;i<=b;i++){
        if(i%k==0){
            result=1;
            break;
        }

    }
    if(result==1)cout<<"OK"<<endl;
    else cout<<"NG"<<endl;
}