#include<bits/stdc++.h>
using namespace std;
int main(){
    int tedad=0;
    map<char,int>charha;
    char x[4];
    cin>>x;
    charha[x[0]]=5;
    for(int i=1;i<4;i++){
        if(charha[x[i]]==5){
            tedad++;
        }
        else{
            charha[x[i]]=5;
        }
    }
    if(tedad==2){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}
