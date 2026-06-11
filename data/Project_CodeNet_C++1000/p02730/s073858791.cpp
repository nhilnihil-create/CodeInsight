#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    
    int l=s.length();
    for(int i=0;i<l/2;i++){
        if(s[i]!=s[l-1-i]){
            cout<<"No"<<endl;
            goto Exit;
        }
    }
    
    for(int i=0;i<(l-1)/4;i++){
        if(s[i]!=s[(l-1)/2-1-i]){
            cout<<"No"<<endl;
            goto Exit;
        }
    }
    
    for(int i=0;i<(l-1)/4;i++){
        if(s[(l+3)/2-1+i]!=s[l-1-i]){
            cout<<"No"<<endl;
            goto Exit;
        }
    }
    
    cout<<"Yes"<<endl;
    
    Exit:
        ;
}