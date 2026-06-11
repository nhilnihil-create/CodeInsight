#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int c=0;
    cin>>s;
    for(int i=0;i<s.size()-1;i++){
        if(s.at(i)==s.at(i+1)){
            c++;
        }
    }
    if(c==0){
        cout<<"Good"<<endl;
    }else{
        cout<<"Bad"<<endl;
    }
}