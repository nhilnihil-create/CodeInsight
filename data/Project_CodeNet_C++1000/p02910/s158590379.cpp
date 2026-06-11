#include <bits/stdc++.h>
using namespace std;
int main(){
    string inp;
    bool a=true,b=true;
    cin >> inp;
    for(int i = 0; i<inp.size(); i +=2 ){
        if((inp[i]!='R')&&(inp[i]!='U')&&(inp[i]!='D')){
            a = a&&false; 
        }
        else{
            a= a&&true;
        }
    }
    for(int i = 1; i<inp.size(); i +=2 ){
        if((inp[i]!='L')&&(inp[i]!='U')&&(inp[i]!='D')){
            b = b&&false; 
        }
        else{
            b= b&&true;
        }
    }
    if(b&&a){
        cout<<"Yes";
    }
    else{
        cout << "No";
    }
}

