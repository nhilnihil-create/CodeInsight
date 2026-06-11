#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    bool flag=true;
    if(n%2>0)flag=false;
    else{
        for(int i=0;2*i<s.size();i++){
            if(s[i]!=s[s.size()/2+i])flag=false;
        }
    }
    if(flag)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}