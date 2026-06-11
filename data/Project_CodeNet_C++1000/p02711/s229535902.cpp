
#include <iostream>
#include<stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,res=-1;
    cin >> n;
    if(n/100%10==7){
        res=1;
    }else if(n/10%10==7){
        res=1;
    }else if(n%10==7){
        res =1;
    }
    if(res==1)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}