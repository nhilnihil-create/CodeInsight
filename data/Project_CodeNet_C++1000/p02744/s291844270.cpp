#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long n;

void dfs(string s,char lim){
    if(s.size()==n){
        cout<<s<<endl;
        return;
    }
    
    for(char i='a';i<=lim+1;i++){
        string hoge;
        hoge.push_back(i);
        dfs(s+hoge,max(i,lim));
    }
}

int main(){
    cin>>n;
    dfs("a",'a');
}
