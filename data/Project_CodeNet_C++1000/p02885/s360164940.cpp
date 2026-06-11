#include<iostream>
using namespace std;
int main(){
    int a,s;
    cin>>a>>s;
    if(s*2<a){
        cout<<(a-s*2);
    }
    else{
        cout<<0;
    }
}