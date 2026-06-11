#include<iostream>
#include<string>
using namespace std;
int main(){
    int i,j,a;
    string x;
    for(;;){
    cin>>x;
    if(x=="0"){
        break;
    }
    for(i=0;i<x.size();i++){
        x[i]=x[i]-'0';
        a+=x[i];
    }
    cout<<a<<endl;
        a=0;
    }
    return 0;
}