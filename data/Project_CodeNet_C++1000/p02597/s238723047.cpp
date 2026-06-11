#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    int n;
    string s;
    cin>>n;
    cin>>s;
    
    bool f=true;
    for(int i=0;i<n;++i){
        if(s[i]=='R'){
            f=false;
            break;
        }
    }
    if(f){
        cout<<0<<endl;
        return 0;
    }
    
    f=true;
    for(int i=0;i<n;++i){
        if(s[i]=='W'){
            f=false;
            break;
        }
    }
    if(f){
        cout<<0<<endl;
        return 0;
    }
    
    int r=0;
    for(int i=0;i<n;++i){
        if(s[i]=='R') ++r;
    }
    int res=0;
    for(int i=0;i<r;++i){
        if(s[i]=='W') ++res;
    }
    
    cout<<res<<endl;
}