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
    int n=s.size();
    for(int i=0;2*i<n-1;i++){
        if(s[i]!=s[n-1-i])flag=false;
    }
    for(int i=0;2*i<(n-1)/2-1;i++){
        if(s[i]!=s[(n-1)/2-1-i])flag=false;
    }
    for(int i=(n+3)/3-1;2*i<n-1;i++){
        if(s[i]!=s[n-1-i])flag=false;
    }
    if(flag)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}