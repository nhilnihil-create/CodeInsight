#include <bits/stdc++.h>
using namespace std;

void solve(int n){
    int ans=0;
    bool l=false,r=false,state=false;
    string str;
    for(int i=0;i<n;i++){
        cin>>str;
        if(str[0]=='l'){
            if(str[1]=='u')l=true;
            else l=false;
        }
        else{
            if(str[1]=='u')r=true;
            else r=false;
        }
        if(l&&r&&!state){
            state=true;
            ans++;
        }
        else if(!l&&!r&&state){
            state=false;
            ans++;
        }
    }
    cout<<ans<<endl;
    
}

int main(void){
    int a;
    while(cin>>a,a){
        solve(a);
    }
    
    
    
}