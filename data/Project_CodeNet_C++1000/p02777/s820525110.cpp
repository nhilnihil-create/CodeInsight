#include <bits/stdc++.h>
using namespace std;

int main(){
    string s,t;
    cin>>s>>t;
    int A,B;
    cin>>A>>B;
    string u;
    cin>>u;
    if(u == s){
        cout<<A-1<<" "<<B<<endl;
    }else{
        cout<<A<<" "<<B-1<<endl;
    }
     
}