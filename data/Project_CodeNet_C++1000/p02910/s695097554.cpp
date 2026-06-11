#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int count;
    for(int i=0;i<s.size();i+=2){
        if(s[i]=='R' || s[i]=='U' || s[i]=='D') count+=0;
        else count+=1;
    }
    for(int i=1;i<s.size();i+=2){
        if(s[i]=='L' || s[i]=='U' ||s[i]=='D') count+=0;
        else count+=1;
    }
    if(count==0)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}