#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cin>>s;
    if(s=="SSS")
        cout<<"0"<<endl;
    else if(s=="RSS")
        cout<<"1"<<endl;
    else if(s=="SRS")
        cout<<"1"<<endl;
    else if(s=="SSR")
        cout<<"1"<<endl;
    else if(s=="RSR")
        cout<<"1"<<endl;
    else if(s=="RRS")
        cout<<"2"<<endl;
    else if(s=="SRR")
        cout<<"2"<<endl;
    else if(s=="RRR")
        cout<<"3"<<endl;
    
    return 0;
}