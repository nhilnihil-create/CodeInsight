#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    string s;
    cin>>s;
    bool flag=true;
    for(int i=0;i<s.size();i++){
        if(i%2==0){
            if(s[i]=='L')flag=false;
        }else{
            if(s[i]=='R')flag=false;
        }
    }
    if(flag)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}