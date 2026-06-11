#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    int ans = 0;
    for(int i = 0;i<s.length();++i){
        ans = (s[i]-48 + ans)%9;
    }
    if(ans){
        cout<<"No";
    }else{
        cout<<"Yes";
    }
    return 0;
}