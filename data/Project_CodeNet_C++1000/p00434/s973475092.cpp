#include<iostream>
using namespace std;
int main(){
    bool s[30];
    for(int i=0;i<30;i++)s[i]=false;
    for(int i=0;i<28;i++){
        int a;
        cin>>a;
        s[a-1]=true;
    }
    for(int i=0;i<30;i++){
        if(!s[i])cout<<i+1<<endl;
    }
    return 0;
}