#include<iostream>
#include<string>
using namespace std;
int main(){
    string a;
    cin>>a;
    if(a>="A" && a<="Z"){
        cout<<"A"<<endl;
    }
    else if(a>="a" && a<="z"){
        cout<<"a"<<endl;
    }
    return 0;
}